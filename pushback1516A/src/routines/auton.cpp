#include "auton.h"
#include "main.h" // IWYU pragma: export
#include "globals.h"

using namespace Robot;
using namespace Robot::Globals;

Autonomous::AUTON_ROUTINE Autonomous::auton = RED_LEFT;
std::string Autonomous::autonName;


void Autonomous::Auton1(pros::Motor intake_motor, pros::Motor hood_motor, pros::ADIDigitalOut piston, pros::ADIDigitalOut odom_lifter, pros::ADIDigitalOut descore, pros::Distance back_sensor, pros::Distance left_sensor, pros::Distance right_sensor) {
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

   chassis.moveToPoint(41, 7, 1000, {.forwards = true});
   chassis.waitUntilDone();
   chassis.swingToHeading(0, DriveSide::RIGHT, 2000);
   chassis.waitUntilDone();

   chassis.moveToPoint(21, 73, 2000);
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

   chassis.moveToPoint(41, 7, 1000, {.forwards = true});
   chassis.waitUntilDone();
   chassis.swingToHeading(0, DriveSide::RIGHT, 2000);
   chassis.waitUntilDone();

   chassis.moveToPoint(21, 73, 2000);
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




void Autonomous::Auton2(pros::Motor intake_motor, pros::Motor hood_motor, pros::ADIDigitalOut piston, pros::ADIDigitalOut odom_lifter, pros::ADIDigitalOut descore, pros::Distance back_sensor, pros::Distance left_sensor, pros::Distance right_sensor) {
   chassis.setPose(0, 0, 0);
   pros::lcd::print(0, "x: %.2f y: %.2f theta: %.2f", chassis.getPose().x, chassis.getPose().y, chassis.getPose().theta);
	chassis.moveToPose(-17, -30, 90, 1250, {.forwards = false, .horizontalDrift = 2, .lead = 0.3});
	chassis.waitUntilDone();

	intake_motor.move_voltage(-12000);
	chassis.moveToPoint(16, -30, 2000, {.forwards = true, .minSpeed = 100});
	chassis.waitUntilDone();
	chassis.moveToPose(27, 0, 0, 3000, {.forwards = true, .horizontalDrift = 2, .lead = 0.5, .minSpeed = 70});
	chassis.waitUntilDone();
	chassis.turnToHeading(0, 2000, {}, true);
   chassis.waitUntilDone();
   pros::delay(200);
   int tube = (chassis.getPose().x + ((left_sensor.get_distance() - 440) / 25.4));
   pros::screen::print(pros::E_TEXT_MEDIUM, 4, "tube pos: %d, dis: %d, current: %2f", tube, left_sensor.get_distance(), chassis.getPose().x);
   pros::delay(200);
   piston.set_value(true);
   pros::delay(200);
	chassis.moveToPose(tube, 20, 0, 1000, {.forwards = true, .maxSpeed = 80, .minSpeed = 70});
   chassis.waitUntilDone();
   chassis.moveToPoint(chassis.getPose().x, 22, 700, {.forwards = true, .minSpeed = 100});
	for(int i = 0; i<2; i++){
		chassis.moveToPoint(chassis.getPose().x, 21, 700, {.forwards = false, .minSpeed = 70});
		chassis.moveToPoint(chassis.getPose().x, 22, 1000, {.forwards = true, .minSpeed = 100});
	}
   pros::delay(2000);

   chassis.moveToPose(tube, -5, 0, 1000, {.forwards = false});
   chassis.turnToHeading(0, 2000, {}, true);
   chassis.waitUntilDone();
   pros::delay(200);
   int goal = (chassis.getPose().x + ((left_sensor.get_distance() - 395) / 25.4));
   pros::screen::print(pros::E_TEXT_MEDIUM, 6, "goal pos: %d, dis: %d, current: %2f", goal, left_sensor.get_distance(), chassis.getPose().x);
   pros::delay(500);
   piston.set_value(false);
	chassis.moveToPose(goal, -22, 0, 2000, {.forwards = false, .horizontalDrift = 2, .lead = 0.4});
   chassis.waitUntilDone();
   intake_motor.move_voltage(-12000);
	hood_motor.move_voltage(-12000);
   pros::delay(4000);
	intake_motor.move_voltage(0);
   hood_motor.move_voltage(0);

   intake_motor.move_voltage(-12000);
	chassis.moveToPose(12, -2, 270, 7000, {.forwards = true, .horizontalDrift = 2, .lead = 0.6, .minSpeed = 90, .earlyExitRange = 0.5});
	chassis.moveToPose(2, -60, 180, 3000, {.forwards = true, .horizontalDrift = 2, .lead = 0.5});
   chassis.turnToHeading(180, 2000);
   chassis.waitUntilDone();
   chassis.moveToPoint(2, -100, 7000, {.forwards = true});
   chassis.waitUntilDone();
   intake_motor.move_voltage(0);
   

   chassis.turnToHeading(180, 2000, {}, true);
   chassis.waitUntilDone();
   pros::delay(500);
   pros::screen::print(pros::E_TEXT_MEDIUM, 7, "dis: %d, current: %2f", left_sensor.get_distance(), chassis.getPose().x);
   
   
   
   // chassis.turnToHeading(90, 2000);
   // chassis.waitUntilDone();

   // chassis.moveToPose(40.5, -125, 180, 2000, {.forwards = true, .horizontalDrift = 2});
   // chassis.moveToPoint(40.5, -100, 3000, {.forwards = false, .minSpeed = 100});
   // piston.set_value(true);
}


void Autonomous::Auton3(pros::Motor intake_motor, pros::Motor hood_motor, pros::ADIDigitalOut piston, pros::ADIDigitalOut odom_lifter, pros::ADIDigitalOut descore, pros::Distance back_sensor, pros::Distance left_sensor, pros::Distance right_sensor) {
   // Placeholder for a third autonomous routine

   odom_lifter.set_value(true); // lower odom lifter
   chassis.setPose(0, 0, 0);
   pros::lcd::print(0, "x: %.2f y: %.2f theta: %.2f", chassis.getPose().x, chassis.getPose().y, chassis.getPose().theta);
   // Add autonomous actions here
   chassis.moveToPoint(0, 4.5, 1000, {.forwards = true});
   intake_motor.move_voltage(-12000);

   chassis.turnToPoint(-21, 28, 1000);
   chassis.waitUntilDone();
   chassis.moveToPoint(-21, 28, 2000, {.forwards = true, .maxSpeed = 70}, false);
   chassis.waitUntilDone();

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

   //descore.set_value(true);

   // chassis.moveToPoint(-41, 4, 2000, {.forwards = true, .minSpeed = 70, .earlyExitRange = 1.0});
   // chassis.waitUntilDone();

   // chassis.moveToPoint(-35, 10, 2000, {.forwards = false});
   // chassis.waitUntilDone();

   // chassis.moveToPoint(-41, 16, 2000, {.forwards = false});
   // chassis.waitUntilDone();

   // chassis.turnToHeading(180, 2000);
   // chassis.waitUntilDone();


   


   //chassis.turnToPoint(-27, 17, 2000, {.forwards = false});
   //chassis.waitUntilDone();
   //chassis.moveToPoint(-27, 17, 2000, {.forwards = false});
   //chassis.waitUntilDone();

   //chassis.moveToPose(-2)


   // chassis.moveToPoint(-43, -4, 2000, {.forwards = true});
   // chassis.waitUntilDone();

   // chassis.turnToPoint(-41, 0, 1000, {.forwards = false});
   // chassis.waitUntilDone();
   // chassis.moveToPoint(-41, 0, 3000, {.forwards = false});
   // chassis.waitUntilDone();

   // chassis.turnToPoint(-41, 17, 1000, {.forwards = false});
   // chassis.waitUntilDone();
   // chassis.moveToPoint(-41, 17, 2000, {.forwards = false});
   // chassis.waitUntilDone();

   
   descore.set_value(false);

   // chassis.swingToHeading(0, DriveSide::RIGHT, 2000);

   // chassis.waitUntilDone();

   // chassis.moveToPoint(chassis.getPose().x, chassis.getPose().y+15, 3000, {.forwards = true});


   // chassis.moveToPoint(-40, 7, 3000, {.forwards = true});
   
   // chassis.turnToPoint(-28, 7, 2000);
   // chassis.waitUntilDone();
   // chassis.moveToPoint(-28, 7, 2000, {.forwards = true});

   // chassis.turnToHeading(0, 2000);
   // chassis.waitUntilDone();
   // chassis.moveToPoint(-28, 22, 3000, {.forwards = true});

}


void Autonomous::Auton4(pros::Motor intake_motor, pros::Motor hood_motor, pros::ADIDigitalOut piston, pros::ADIDigitalOut odom_lifter, pros::ADIDigitalOut descore, pros::Distance back_sensor, pros::Distance left_sensor, pros::Distance right_sensor) {
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


   // chassis.swingToHeading(0, DriveSide::RIGHT, 1000);
   // chassis.waitUntilDone();
   //chassis.moveToPoint(39, 17, 2000, {.forwards = true});
   //chassis.waitUntilDone();
}


void Autonomous::AutoDrive(pros::Motor intake_motor, pros::Motor hood_motor, pros::ADIDigitalOut piston, pros::ADIDigitalOut odom_lifter, pros::ADIDigitalOut descore, pros::Distance back_sensor, pros::Distance left_sensor, pros::Distance right_sensor) {
   // Keep the switcher running while the controller down button has not been pressed and the time period is not
   // autonomous Compare the current auton value to run the auton routine
   switch (Autonomous::auton) {
   case RED_LEFT:
      Auton4(intake_motor, hood_motor, piston, odom_lifter, descore, back_sensor, left_sensor, right_sensor);
      break;
   case RED_RIGHT:
      Auton3(intake_motor, hood_motor, piston, odom_lifter, descore, back_sensor, left_sensor, right_sensor);
      break;
   case BLUE_LEFT:
      Auton3(intake_motor, hood_motor, piston, odom_lifter, descore, back_sensor, left_sensor, right_sensor);
      break;
   case BLUE_RIGHT:
      Auton4(intake_motor, hood_motor, piston, odom_lifter, descore, back_sensor, left_sensor, right_sensor);
      break;
   case SKILLS:
      Auton1(intake_motor, hood_motor, piston, odom_lifter, descore, back_sensor, left_sensor, right_sensor);
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