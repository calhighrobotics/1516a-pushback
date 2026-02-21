#include "lemlib/api.hpp"
#include "pros/misc.h"
#include "pros/motors.h"
#include "auton.h"
#include "main.h" // IWYU pragma: export
#include "globals.h"
#include "paths.h"
#include <string>
#include "distance_reset.h"

using namespace Robot;
using namespace Robot::Globals;

Autonomous::AUTON_ROUTINE Autonomous::auton = RED_LEFT;
std::string Autonomous::autonName;


void followPath(std::vector<PathPoint> path, bool frw = true) {
   bool odom_state = true;
   bool indexer_state = false;
   bool mloader_state = false;
   bool extender_state = false;
   
   std::vector<double> global_distance;
   
   for (int pointNum = 0; pointNum < path.size(); pointNum++) {
      PathPoint point = path[pointNum];

      
      if (point.action.find("INTAKE") != std::string::npos) {
         intake_motor.move_voltage(-12000);
      }
      if (point.action.find("STOP") != std::string::npos) {
         intake_motor.move_voltage(0);
         hood_motor.move_voltage(0);
      }
      if (point.action.find("ODOM") != std::string::npos) {
         odom_lifter.set_value(!odom_state);
         odom_state = !odom_state;  
      }
      if (point.action.find("INDEXER") != std::string::npos) {
         indexer.set_value(!indexer_state);
         indexer_state = !indexer_state;
      }
      if (point.action.find("MLOADER") != std::string::npos) {
         mloader.set_value(!mloader_state);
         mloader_state = !mloader_state;
      }
      if (point.action.find("EXTENDER") != std::string::npos) {
         extender.set_value(!extender_state);
         extender_state = !extender_state;
      }

      if (point.action.find("REVERSE") != std::string::npos) {
         frw = !frw;
      }

      if (point.type == "Point") {
         chassis.turnToPoint(point.x, point.y, point.timeout/2, {.forwards = frw});
         chassis.waitUntilDone();
         chassis.moveToPoint(point.x, point.y, point.timeout, {.forwards = frw, .maxSpeed = (point.speed+10), .minSpeed = (point.speed-10)});
         chassis.waitUntilDone();
         chassis.turnToHeading(point.heading, point.timeout/1.5);
         chassis.waitUntilDone();
         pros::screen::print(pros::E_TEXT_MEDIUM, 0, "x: %.2f y: %.2f theta: %.2f", chassis.getPose().x, chassis.getPose().y, chassis.getPose().theta);

      } else if (point.type == "Chained") {
         chassis.moveToPose(point.x, point.y, point.heading, point.timeout, {.forwards = frw, .maxSpeed = (point.speed+10), .minSpeed = (point.speed-10), .earlyExitRange = 1.0});
         pros::screen::print(pros::E_TEXT_MEDIUM, 0, "x: %.2f y: %.2f theta: %.2f", chassis.getPose().x, chassis.getPose().y, chassis.getPose().theta);

      }else if (point.type == "Pose") {
         chassis.moveToPose(point.x, point.y, point.heading, point.timeout, {.forwards = frw, .maxSpeed = (point.speed+10), .minSpeed = (point.speed-10)});
         chassis.waitUntilDone();
         pros::screen::print(pros::E_TEXT_MEDIUM, 0, "x: %.2f y: %.2f theta: %.2f", chassis.getPose().x, chassis.getPose().y, chassis.getPose().theta);

      }else if (point.type == "SwingLEFT") {
         chassis.swingToPoint(point.x, point.y, DriveSide::LEFT, point.timeout, {.forwards = frw, .maxSpeed = (point.speed+10), .minSpeed = (point.speed-10)});
         chassis.waitUntilDone();
      }
      else if (point.type == "SwingRIGHT") {
         chassis.swingToPoint(point.x, point.y, DriveSide::RIGHT, point.timeout, {.forwards = frw, .maxSpeed = (point.speed+10), .minSpeed = (point.speed-10)});
         chassis.waitUntilDone();
         chassis.turnToHeading(point.heading, point.timeout);
         chassis.waitUntilDone();
      }

      if (point.action.find("SCORE") != std::string::npos) {
         intake_motor.move_voltage(-12000);
         hood_motor.move_voltage(-12000);
      } 

      if (point.action.find("DIST") != std::string::npos) {
         bool front, back, left, right = false;
         if (point.action.find("FRONT") != std::string::npos) front = true;
         if (point.action.find("BACK") != std::string::npos) back = true;
         if (point.action.find("LEFT") != std::string::npos) left = true;
         if (point.action.find("RIGHT") != std::string::npos) right = true;
         global_distance = getDistanceReset(front, back, left, right);
         chassis.setPose(global_distance[0], global_distance[1], chassis.getPose().theta);
         
      }
      
      pros::delay(point.delay);
      intake_motor.move_voltage(0);
      hood_motor.move_voltage(0);
   }
}

//IGNORE
void Autonomous::Auton1(pros::Motor intake_motor, pros::Motor hood_motor, pros::ADIDigitalOut piston, pros::ADIDigitalOut odom_lifter, pros::ADIDigitalOut descore, pros::ADIDigitalOut indexer, pros::ADIDigitalOut extender, pros::Distance back_sensor, pros::Distance left_sensor, pros::Distance right_sensor) {
   chassis.setPose(-62, 14, 180);

   //extender.set_value(true); // extend the extender

   intake_motor.move_voltage(-12000);
   chassis.moveToPoint(-62, -35, 2000, {.forwards = true});
   chassis.waitUntilDone();
   intake_motor.move_voltage(0);
   odom_lifter.set_value(true); // lower odom lifter

   chassis.turnToPoint(24, -12, 500, {.forwards = false});
   chassis.waitUntilDone();

   //followPath("routes/pt1.txt", false);

   chassis.turnToHeading(225, 500);
   chassis.waitUntilDone();
   intake_motor.move_voltage(-12000);
   pros::delay(2000);
   intake_motor.move_voltage(0);

   //followPath("routes/pt2.txt", 2000, true);
}
//IGNORE


// skills auton
void Autonomous::Auton2(pros::Motor intake_motor, pros::Motor hood_motor, pros::ADIDigitalOut piston, pros::ADIDigitalOut odom_lifter, pros::ADIDigitalOut descore, pros::ADIDigitalOut indexer, pros::ADIDigitalOut extender, pros::Distance back_sensor, pros::Distance left_sensor, pros::Distance right_sensor) {
   extender.set_value(true); // extend the extender
   descore.set_value(true); // deploy descore mechanis
   odom_lifter.set_value(true);
   pros::delay(400);
   chassis.setPose(-45.5, 0, 180);
   followPath(Paths::skills, true);
}

// match auton - right side
void Autonomous::Auton3(pros::Motor intake_motor, pros::Motor hood_motor, pros::ADIDigitalOut piston, pros::ADIDigitalOut odom_lifter, pros::ADIDigitalOut descore, pros::ADIDigitalOut indexer, pros::ADIDigitalOut extender, pros::Distance back_sensor, pros::Distance left_sensor, pros::Distance right_sensor) {
   odom_lifter.set_value(true); // lower odom lifter 
   extender.set_value(true); // extend the extender
   pros::delay(400);
   chassis.setPose(44, 8, 270);
   followPath(Paths::right);

}

// match auton - left side
void Autonomous::Auton4(pros::Motor intake_motor, pros::Motor hood_motor, pros::ADIDigitalOut piston, pros::ADIDigitalOut odom_lifter, pros::ADIDigitalOut descore, pros::ADIDigitalOut indexer, pros::ADIDigitalOut extender, pros::Distance back_sensor, pros::Distance left_sensor, pros::Distance right_sensor) {
   odom_lifter.set_value(true); // lower odom lifter 
   extender.set_value(true); // extend the extender
   pros::delay(400);
   chassis.setPose(44, -8, 270);
   followPath(Paths::left);
}


void Autonomous::AutoDrive(pros::Motor intake_motor, pros::Motor hood_motor, pros::ADIDigitalOut piston, pros::ADIDigitalOut odom_lifter, pros::ADIDigitalOut descore, pros::ADIDigitalOut indexer, pros::ADIDigitalOut extender, pros::Distance back_sensor, pros::Distance left_sensor, pros::Distance right_sensor) {
   // Keep the switcher running while the controller down button has not been pressed and the time period is not
   // autonomous Compare the current auton value to run the auton routine
   switch (Autonomous::auton) {
   case RED_LEFT:
      Auton4(intake_motor, hood_motor, piston, odom_lifter, descore, indexer, extender, back_sensor, left_sensor, right_sensor);
      break;
   case RED_RIGHT:
      Auton3(intake_motor, hood_motor, piston, odom_lifter, descore, indexer, extender, back_sensor, left_sensor, right_sensor);
      break;
   case BLUE_LEFT:
      Auton4(intake_motor, hood_motor, piston, odom_lifter, descore, indexer, extender, back_sensor, left_sensor, right_sensor);
      break;
   case BLUE_RIGHT:
      Auton3(intake_motor, hood_motor, piston, odom_lifter, descore, indexer, extender, back_sensor, left_sensor, right_sensor);
      break;
   case SKILLS:
      Auton2(intake_motor, hood_motor, piston, odom_lifter, descore, indexer, extender, back_sensor, left_sensor, right_sensor);
      break;
   }
}

void Autonomous::AutonSwitcher(int autonNum) {
   switch (autonNum) {
   case 1:
      Autonomous::autonName = "Red Left";
      Autonomous::auton = RED_LEFT;
      break;
   case 2:
      Autonomous::autonName = "Red Right";
      Autonomous::auton = RED_RIGHT;
      break;
   case -1:
      Autonomous::autonName = "Blue Left";
      Autonomous::auton = BLUE_LEFT;
      break;
   case -2:
      Autonomous::autonName = "Blue Right";
      Autonomous::auton = BLUE_RIGHT;
      break;
   case 0:
      Autonomous::autonName = "Skills";
      Autonomous::auton = SKILLS;
   }
   std::cout << "Current auton: " + Autonomous::autonName << std::endl;
}