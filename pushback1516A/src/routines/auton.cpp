#include "auton.h"
#include "main.h" // IWYU pragma: export
#include "globals.h"

using namespace Robot;
using namespace Robot::Globals;

Autonomous::AUTON_ROUTINE Autonomous::auton = RED_LEFT;
std::string Autonomous::autonName;


void Autonomous::Auton1(pros::Motor intake_motor, pros::Motor hood_motor, pros::ADIDigitalOut piston, pros::ADIDigitalOut odom_lifter, pros::ADIDigitalOut descore, pros::ADIDigitalOut indexer, pros::ADIDigitalOut extender, pros::Distance back_sensor, pros::Distance left_sensor, pros::Distance right_sensor) {
   //Auton 4
   odom_lifter.set_value(true); // lower odom lifter
   chassis.setPose(0, 0, 0);
   pros::lcd::print(0, "x: %.2f y: %.2f theta: %.2f", chassis.getPose().x, chassis.getPose().y, chassis.getPose().theta);
   // Add autonomous actions here
   chassis.moveToPoint(0, 4.5, 1000, {.forwards = true});
   intake_motor.move_voltage(-12000);

   chassis.turnToPoint(21, 28, 1000);
   chassis.waitUntilDone();
   chassis.moveToPoint(21, 28, 2000, {.forwards = true, .maxSpeed = 70}, false);
   chassis.waitUntilDone();

   intake_motor.move_voltage(0);

   chassis.turnToPoint(43, -2, 1000);
   chassis.waitUntilDone();
   chassis.moveToPoint(43, -2, 1500, {.forwards = true});
   piston.set_value(true);

   chassis.waitUntilDone();

   chassis.turnToHeading(180, 1000);
   chassis.waitUntilDone();

   intake_motor.move_voltage(-12000);


   // chassis.turnToPoint(39, -15, 1000);
   // chassis.waitUntilDone();
   chassis.moveToPoint(41, -15, 3000, {.forwards = true, .minSpeed = 100});
   chassis.waitUntilDone();

   pros::delay(1500);

   intake_motor.move_voltage(0);

   chassis.moveToPoint(41, 15, 1000, {.forwards = false});
   chassis.waitUntilDone();

   piston.set_value(false);

   intake_motor.move_voltage(-12000);
   hood_motor.move_voltage(-12000);
   pros::delay(2500);

   intake_motor.move_voltage(0);
   hood_motor.move_voltage(0);

   // move to Auton 3

   chassis.moveToPoint(41, 5, 1000, {.forwards = true});
   chassis.waitUntilDone();
   chassis.swingToHeading(0, DriveSide::RIGHT, 2000);
   chassis.waitUntilDone();

   chassis.moveToPoint(21, 73, 2000,{.forwards = true});
   chassis.waitUntilDone();
   chassis.turnToHeading(0, 1000);
   chassis.waitUntilDone();


   
   chassis.setPose(-21, 28, 180);

   //Auton 3
   intake_motor.move_voltage(0);

   chassis.turnToPoint(-43, -2, 1000);
   chassis.waitUntilDone();
   chassis.moveToPoint(-43, -2, 1500, {.forwards = true});
   piston.set_value(true);

   chassis.waitUntilDone();

   chassis.turnToHeading(180, 1000);
   chassis.waitUntilDone();

   intake_motor.move_voltage(-12000);

   chassis.moveToPoint(-41, -15, 3000, {.forwards = true, .minSpeed = 100});
   chassis.waitUntilDone();

   pros::delay(1500);

   intake_motor.move_voltage(0);

   chassis.moveToPoint(-41, 15, 1000, {.forwards = false});
   chassis.waitUntilDone();

   piston.set_value(false);

   intake_motor.move_voltage(-12000);
   hood_motor.move_voltage(-12000);
   pros::delay(2500);

   intake_motor.move_voltage(0);
   hood_motor.move_voltage(0);

   // move to auton 4

   chassis.moveToPoint(-41, 7, 1000, {.forwards = true});
   chassis.waitUntilDone();

   chassis.moveToPose(-21, 28, 90, 6000, {.forwards = true, .horizontalDrift = 2});
   chassis.waitUntilDone();

   intake_motor.move_voltage(-12000);

   chassis.moveToPoint(21, 28, 5000, {.forwards = true});
   chassis.waitUntilDone();
   intake_motor.move_voltage(0);
   chassis.turnToHeading(180, 2000);

   chassis.setPose(21, 28, 180);

   // auton 4

   chassis.turnToPoint(43, -2, 1000);
   chassis.waitUntilDone();
   chassis.moveToPoint(43, -2, 1500, {.forwards = true});
   piston.set_value(true);

   chassis.waitUntilDone();

   chassis.turnToHeading(180, 1000);
   chassis.waitUntilDone();

   intake_motor.move_voltage(-12000);


   // chassis.turnToPoint(39, -15, 1000);
   // chassis.waitUntilDone();
   chassis.moveToPoint(41, -15, 3000, {.forwards = true, .minSpeed = 100});
   chassis.waitUntilDone();

   pros::delay(1500);

   intake_motor.move_voltage(0);

   chassis.moveToPoint(41, 15, 1000, {.forwards = false});
   chassis.waitUntilDone();

   piston.set_value(false);

   intake_motor.move_voltage(-12000);
   hood_motor.move_voltage(-12000);
   pros::delay(2500);

   intake_motor.move_voltage(0);
   hood_motor.move_voltage(0);

   // move to auton 3

   chassis.moveToPoint(41, 5, 1000, {.forwards = true});
   chassis.waitUntilDone();
   chassis.swingToHeading(0, DriveSide::RIGHT, 2000);
   chassis.waitUntilDone();

   chassis.moveToPoint(21, 73, 2000, {.forwards = true});
   chassis.waitUntilDone();
   chassis.turnToHeading(0, 1000);
   chassis.waitUntilDone();

   chassis.setPose(-21, 28, 180);

   // auton 3

   intake_motor.move_voltage(0);

   chassis.turnToPoint(-43, -2, 1000);
   chassis.waitUntilDone();
   chassis.moveToPoint(-43, -2, 1500, {.forwards = true});
   piston.set_value(true);

   chassis.waitUntilDone();

   chassis.turnToHeading(180, 1000);
   chassis.waitUntilDone();

   intake_motor.move_voltage(-12000);

   chassis.moveToPoint(-41, -15, 3000, {.forwards = true, .minSpeed = 100});
   chassis.waitUntilDone();

   pros::delay(1500);

   intake_motor.move_voltage(0);

   chassis.moveToPoint(-41, 15, 1000, {.forwards = false});
   chassis.waitUntilDone();

   piston.set_value(false);

   intake_motor.move_voltage(-12000);
   hood_motor.move_voltage(-12000);
   pros::delay(2500);

   intake_motor.move_voltage(0);
   hood_motor.move_voltage(0);

}




void Autonomous::Auton2(pros::Motor intake_motor, pros::Motor hood_motor, pros::ADIDigitalOut piston, pros::ADIDigitalOut odom_lifter, pros::ADIDigitalOut descore, pros::ADIDigitalOut indexer, pros::ADIDigitalOut extender, pros::Distance back_sensor, pros::Distance left_sensor, pros::Distance right_sensor) {
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
   chassis.moveToPoint(23, -24, 1000, {.forwards = true, .maxSpeed = 70, .earlyExitRange = 1.0});
   chassis.waitUntilDone();
   piston.set_value(true);
   chassis.moveToPoint(19, -27, 1000, {.forwards = true, .maxSpeed = 70}, false);

   intake_motor.move_voltage(0);
   //piston.set_value(false);

   chassis.turnToPoint(-5, 5, 600, {.forwards = false});
   chassis.waitUntilDone();
   chassis.moveToPoint(6, -7, 500, {.forwards = false});
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


   chassis.moveToPoint(60, -47, 1000, {.forwards = true, .maxSpeed = 90, .minSpeed = 70});
   chassis.waitUntilDone();

   pros::delay(150);

   intake_motor.move_voltage(0);

   chassis.turnToPoint(25, -48, 1000, {.forwards = false});
   chassis.waitUntilDone();

   chassis.moveToPoint(25, -48, 1500, {.forwards = false});
   chassis.waitUntilDone();

   piston.set_value(false);

   intake_motor.move_voltage(-12000);
   hood_motor.move_voltage(-12000);
   pros::delay(1500);

   intake_motor.move_voltage(0);
   hood_motor.move_voltage(0);

   chassis.moveToPoint(32, -48, 1000, {.forwards = true});
   chassis.waitUntilDone();


   chassis.swingToHeading(0, DriveSide::LEFT, 1000);
   chassis.waitUntilDone();

   //auton 3

   chassis.turnToPoint(23, 27, 800);
   chassis.waitUntilDone();
   chassis.moveToPoint(23, 19, 3000, {.forwards = true, .minSpeed = 70, .earlyExitRange = 1.0});
   chassis.waitUntilDone();
   piston.set_value(true);
   chassis.moveToPoint(23, 27, 1000, {.forwards = true}, false);
   chassis.waitUntilDone();

   intake_motor.move_voltage(0);
   chassis.turnToPoint(46, 49.5, 800);
   chassis.waitUntilDone();
   chassis.moveToPoint(46, 49.5, 1500);
   indexer.set_value(true);

   chassis.waitUntilDone();

   chassis.turnToHeading(90, 500);
   chassis.waitUntilDone();

   intake_motor.move_voltage(-12000);


   chassis.moveToPoint(60, 48, 1000, {.forwards = true, .maxSpeed = 90, .minSpeed = 70});
   chassis.waitUntilDone();

   pros::delay(150);

   intake_motor.move_voltage(0);

   chassis.turnToPoint(25, 50, 1000, {.forwards = false});
   chassis.waitUntilDone();

   chassis.moveToPoint(25, 50, 1500, {.forwards = false});
   chassis.waitUntilDone();

   piston.set_value(false);

   intake_motor.move_voltage(-12000);
   hood_motor.move_voltage(-12000);
   pros::delay(700);

   intake_motor.move_voltage(0);
   hood_motor.move_voltage(0);

   chassis.moveToPoint(32, 50, 1000, {.forwards = true});
   chassis.waitUntilDone();

   
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
   chassis.moveToPoint(19, 27, 1000, {.forwards = true, .maxSpeed = 70}, false);
   chassis.waitUntilDone();

   intake_motor.move_voltage(0);
   //piston.set_value(false);

   chassis.turnToPoint(46, 49.5, 800);
   chassis.waitUntilDone();
   chassis.moveToPoint(46, 49.5, 1500);
   indexer.set_value(true);

   chassis.waitUntilDone();

   chassis.turnToHeading(90, 500);
   chassis.waitUntilDone();

   intake_motor.move_voltage(-12000);


   chassis.moveToPoint(60, 48, 1000, {.forwards = true, .maxSpeed = 90, .minSpeed = 70});
   chassis.waitUntilDone();

   pros::delay(150);

   intake_motor.move_voltage(0);

   chassis.turnToPoint(25, 50, 1000, {.forwards = false});
   chassis.waitUntilDone();

   chassis.moveToPoint(25, 50, 1500, {.forwards = false});
   chassis.waitUntilDone();

   piston.set_value(false);

   intake_motor.move_voltage(-12000);
   hood_motor.move_voltage(-12000);
   pros::delay(700);

   intake_motor.move_voltage(0);
   hood_motor.move_voltage(0);

   chassis.moveToPoint(32, 50, 1000, {.forwards = true});
   chassis.waitUntilDone();


   chassis.swingToHeading(180, DriveSide::RIGHT, 1000);
   chassis.waitUntilDone();
   chassis.moveToPoint(35, 37, 600, {.forwards = true});
   chassis.waitUntilDone();
   chassis.turnToHeading(275, 500, {.direction = AngularDirection::CW_CLOCKWISE});
   chassis.waitUntilDone();
   chassis.moveToPoint(11, 38, 1500, {.forwards = true});

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
   chassis.moveToPoint(23, -24, 1000, {.forwards = true, .maxSpeed = 70, .earlyExitRange = 1.0});
   chassis.waitUntilDone();
   piston.set_value(true);
   chassis.moveToPoint(19, -27, 1000, {.forwards = true, .maxSpeed = 70}, false);

   intake_motor.move_voltage(0);
   //piston.set_value(false);

   chassis.turnToPoint(-5, 5, 600, {.forwards = false});
   chassis.waitUntilDone();
   chassis.moveToPoint(6, -7, 500, {.forwards = false});
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


   chassis.moveToPoint(60, -47, 1000, {.forwards = true, .maxSpeed = 90, .minSpeed = 70});
   chassis.waitUntilDone();

   pros::delay(150);

   intake_motor.move_voltage(0);

   chassis.turnToPoint(25, -48, 1000, {.forwards = false});
   chassis.waitUntilDone();

   chassis.moveToPoint(25, -48, 1500, {.forwards = false});
   chassis.waitUntilDone();

   piston.set_value(false);

   intake_motor.move_voltage(-12000);
   hood_motor.move_voltage(-12000);
   pros::delay(1500);

   intake_motor.move_voltage(0);
   hood_motor.move_voltage(0);

   chassis.moveToPoint(32, -48, 1000, {.forwards = true});
   chassis.waitUntilDone();


   chassis.swingToHeading(0, DriveSide::LEFT, 1000);
   chassis.waitUntilDone();
   chassis.moveToPoint(35, -34, 600, {.forwards = true});
   chassis.waitUntilDone();
   chassis.turnToHeading(85, 500, {.direction = AngularDirection::CW_CLOCKWISE});
   chassis.waitUntilDone();
   chassis.moveToPoint(17, -35, 1500, {.forwards = false});
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