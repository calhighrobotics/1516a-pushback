#include "auton.h"
#include "main.h" // IWYU pragma: export
#include "globals.h"
#include "parser.h"

using namespace Robot;
using namespace Robot::Globals;

Autonomous::AUTON_ROUTINE Autonomous::auton = RED_LEFT;
std::string Autonomous::autonName;


void followPath(std::vector<PathPoint> path, int delayTime = 0, bool forwards = true) {
   bool odom_state = true;
   bool indexer_state = false;
   bool mloader_state = false;
   bool extender_state = false;
   
   for (int pointNum = 0; pointNum < path.size(); pointNum++) {
      PathPoint point = path[pointNum];

      if (point.type == MOVETOPOINT) {
         chassis.moveToPoint(point.x, point.y, 500, {.forwards = forwards, .maxSpeed = (float) (point.speed+10), .minSpeed = (float) (point.speed-10), .earlyExitRange = 1.0});
         chassis.waitUntilDone();
      } else if (point.type == MOVETOPOSE) {
         chassis.moveToPose(point.x, point.y, point.heading, 700, {.forwards = forwards, .maxSpeed = (float) (point.speed+10), .minSpeed = (float) (point.speed-10), .earlyExitRange = 1.0});
         chassis.waitUntilDone();
      }

      if (point.action == "INTAKE") {
         intake_motor.move_voltage(-12000);
      } else if (point.action == "SCORE") {
         intake_motor.move_voltage(-12000);
         hood_motor.move_voltage(-12000);
         pros::delay(delayTime);
      } else if (point.action == "STOP") {
         intake_motor.move_voltage(0);
         hood_motor.move_voltage(0);
      } else if (point.action == "ODOM") {
         odom_lifter.set_value(!odom_state);
         odom_state = !odom_state;  
      } else if (point.action == "INDEXER") {
         indexer.set_value(!indexer_state);
         indexer_state = !indexer_state;
      } else if (point.action == "MLOADER") {
         mloader.set_value(!mloader_state);
         mloader_state = !mloader_state;
      } else if (point.action == "EXTENDER") {
         extender.set_value(!extender_state);
         extender_state = !extender_state;
      }
   }
}


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




void Autonomous::Auton2(pros::Motor intake_motor, pros::Motor hood_motor, pros::ADIDigitalOut piston, pros::ADIDigitalOut odom_lifter, pros::ADIDigitalOut descore, pros::ADIDigitalOut indexer, pros::ADIDigitalOut extender, pros::Distance back_sensor, pros::Distance left_sensor, pros::Distance right_sensor) {
   odom_lifter.set_value(true); // lower odom lifter 
   extender.set_value(true); // extend the extender

   chassis.setPose(63, -17, 270);
   // chassis.moveToPoint(63, -35, 500, {.forwards = true});
   // chassis.waitUntilDone();

   //followPath("test.txt", 2500, true);
   
   
}


void Autonomous::Auton3(pros::Motor intake_motor, pros::Motor hood_motor, pros::ADIDigitalOut piston, pros::ADIDigitalOut odom_lifter, pros::ADIDigitalOut descore, pros::ADIDigitalOut indexer, pros::ADIDigitalOut extender, pros::Distance back_sensor, pros::Distance left_sensor, pros::Distance right_sensor) {
   odom_lifter.set_value(true); // lower odom lifter 
   extender.set_value(true); // extend the extender

   chassis.setPose(44, 8, 270);

   chassis.moveToPoint(39, 8, 500, {.forwards = true});
   chassis.waitUntilDone();
   pros::lcd::print(0, "x: %.2f y: %.2f theta: %.2f", chassis.getPose().x, chassis.getPose().y, chassis.getPose().theta);
   // Add autonomous actions here
   intake_motor.move_voltage(-12000);

   chassis.turnToPoint(19, 27, 800);
   chassis.waitUntilDone();
   chassis.moveToPoint(23, 24, 1000, {.forwards = true, .maxSpeed = 70, .earlyExitRange = 1.0});
   chassis.waitUntilDone();
   piston.set_value(true);

   intake_motor.move_voltage(0);
   //piston.set_value(false);

   chassis.turnToPoint(46, 47.5, 800);
   chassis.waitUntilDone();
   chassis.moveToPoint(46, 47.5, 1500);
   indexer.set_value(true);

   chassis.waitUntilDone();

   chassis.turnToHeading(90, 500);
   chassis.waitUntilDone();

   intake_motor.move_voltage(-12000);


   chassis.moveToPoint(60, 46, 1000, {.forwards = true, .maxSpeed = 90, .minSpeed = 70});
   chassis.waitUntilDone();

   pros::delay(150);

   intake_motor.move_voltage(0);

   chassis.turnToPoint(25, 45, 1000, {.forwards = false});
   chassis.waitUntilDone();

   chassis.moveToPoint(25, 45, 1500, {.forwards = false});
   chassis.waitUntilDone();

   piston.set_value(false);

   intake_motor.move_voltage(-12000);
   hood_motor.move_voltage(-12000);
   pros::delay(700);

   intake_motor.move_voltage(0);
   hood_motor.move_voltage(0);

   chassis.moveToPoint(32, 45, 1000, {.forwards = true});
   chassis.waitUntilDone();


   chassis.swingToHeading(180, DriveSide::RIGHT, 1000);
   chassis.waitUntilDone();
   chassis.moveToPoint(35, 31, 600, {.forwards = true});
   chassis.waitUntilDone();
   chassis.turnToHeading(270, 500, {.direction = AngularDirection::CW_CLOCKWISE});
   chassis.waitUntilDone();
   chassis.moveToPoint(17, 31, 1500, {.forwards = true});

}


void Autonomous::Auton4(pros::Motor intake_motor, pros::Motor hood_motor, pros::ADIDigitalOut piston, pros::ADIDigitalOut odom_lifter, pros::ADIDigitalOut descore, pros::ADIDigitalOut indexer, pros::ADIDigitalOut extender, pros::Distance back_sensor, pros::Distance left_sensor, pros::Distance right_sensor) {
   odom_lifter.set_value(true); // lower odom lifter 
   extender.set_value(true); // extend the extender

   chassis.setPose(44, -8, 270);

   chassis.moveToPoint(39, -8, 500, {.forwards = true});
   chassis.waitUntilDone();
   pros::lcd::print(0, "x: %.2f y: %.2f theta: %.2f", chassis.getPose().x, chassis.getPose().y, chassis.getPose().theta);
   // Add autonomous actions here
   intake_motor.move_voltage(-12000);

   chassis.turnToPoint(19, -27, 800);
   chassis.waitUntilDone();
   chassis.moveToPoint(22, -23, 1000, {.forwards = true, .maxSpeed = 70, .earlyExitRange = 1.0});
   chassis.waitUntilDone();
   piston.set_value(true);

   intake_motor.move_voltage(0);
   //piston.set_value(false);

   chassis.turnToPoint(-5, 5, 600, {.forwards = false});
   chassis.waitUntilDone();
   chassis.moveToPoint(12, -8, 500, {.forwards = false});
   chassis.waitUntilDone();
   intake_motor.move_voltage(-12000);
   hood_motor.move_voltage(-12000);
   pros::delay(2500);

   intake_motor.move_voltage(0);
   hood_motor.move_voltage(0);


   chassis.turnToPoint(46, -48.5, 500);
   chassis.waitUntilDone();
   chassis.moveToPoint(46, -48.5, 1500, {.forwards = true});
   indexer.set_value(true);

   chassis.waitUntilDone();

   chassis.turnToHeading(90, 500);
   chassis.waitUntilDone();

   intake_motor.move_voltage(-12000);


   chassis.moveToPoint(60, -47, 500, {.forwards = true, .maxSpeed = 90, .minSpeed = 70});
   chassis.waitUntilDone();

   pros::delay(500);

   intake_motor.move_voltage(0);

   chassis.turnToPoint(25, -46, 1000, {.forwards = false});
   chassis.waitUntilDone();

   chassis.moveToPoint(25, -46, 1500, {.forwards = false});
   chassis.waitUntilDone();

   piston.set_value(false);

   intake_motor.move_voltage(-12000);
   hood_motor.move_voltage(-12000);
   pros::delay(1500);

   intake_motor.move_voltage(0);
   hood_motor.move_voltage(0);

   chassis.moveToPoint(32, -46, 1000, {.forwards = true});
   chassis.waitUntilDone();


   chassis.swingToHeading(0, DriveSide::LEFT, 1000);
   chassis.waitUntilDone();
   chassis.moveToPoint(35, -31, 600, {.forwards = true});
   chassis.waitUntilDone();
   chassis.turnToHeading(90, 500, {.direction = AngularDirection::CW_CLOCKWISE});
   chassis.waitUntilDone();
   chassis.moveToPoint(17, -31, 1500, {.forwards = false});
   // chassis.moveToPoint(39, 17, 2000, {.forwards = true});
   // chassis.waitUntilDone();
}


void Autonomous::AutoDrive(pros::Motor intake_motor, pros::Motor hood_motor, pros::ADIDigitalOut piston, pros::ADIDigitalOut odom_lifter, pros::ADIDigitalOut descore, pros::ADIDigitalOut indexer, pros::ADIDigitalOut extender, pros::Distance back_sensor, pros::Distance left_sensor, pros::Distance right_sensor) {
   // Keep the switcher running while the controller down button has not been pressed and the time period is not
   // autonomous Compare the current auton value to run the auton routine
   switch (Autonomous::auton) {
   case RED_LEFT:
      Auton2(intake_motor, hood_motor, piston, odom_lifter, descore, indexer, extender, back_sensor, left_sensor, right_sensor);
      break;
   case RED_RIGHT:
      Auton2(intake_motor, hood_motor, piston, odom_lifter, descore, indexer, extender, back_sensor, left_sensor, right_sensor);
      break;
   case BLUE_LEFT:
      Auton2(intake_motor, hood_motor, piston, odom_lifter, descore, indexer, extender, back_sensor, left_sensor, right_sensor);
      break;
   case BLUE_RIGHT:
      Auton2(intake_motor, hood_motor, piston, odom_lifter, descore, indexer, extender, back_sensor, left_sensor, right_sensor);
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