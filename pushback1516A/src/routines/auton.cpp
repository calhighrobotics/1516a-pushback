#include "auton.h"
#include "main.h" // IWYU pragma: export
#include "globals.h"

using namespace Robot;
using namespace Robot::Globals;

Autonomous::AUTON_ROUTINE Autonomous::auton = RED_LEFT;
std::string Autonomous::autonName;

void Autonomous::Auton3(pros::Motor intake_motor, pros::Motor hood_motor, pros::ADIDigitalOut piston, pros::Distance distance_sensor) {
   // Placeholder for a third autonomous routine
   chassis.setPose(0, 0, 0);
   pros::lcd::print(0, "x: %.2f y: %.2f theta: %.2f", chassis.getPose().x, chassis.getPose().y, chassis.getPose().theta);
   // Add autonomous actions here
   chassis.moveToPoint(7, 0, 1000, {.forwards = true});
   chassis.turnToPoint(-21, 30, 1000);
   chassis.waitUntilDone();
   chassis.moveToPoint(-21, 30, 2000, {.forwards = true});
   chassis.waitUntilDone();
   chassis.turnToHeading(180, 2000);
   chassis.waitUntilDone();
   pros::delay(200); 

   chassis.moveToPose(-26, 12, 210, 2000, {.forwards = true, .horizontalDrift = 2, .lead = 0.4, .minSpeed = 70, .earlyExitRange = 1});
   chassis.moveToPose(-38, 3, 270, 3000, {.forwards = true, .horizontalDrift = 2, .lead = 0.5, .minSpeed = 70});
   chassis.waitUntilDone();
   chassis.turnToHeading(180, 2000);

   pros::delay(200);
   int tube = (chassis.getPose().x + ((distance_sensor.get_distance() - 440) / 25.4));
   pros::screen::print(pros::E_TEXT_MEDIUM, 4, "tube pos: %d, dis: %d, current: %2f", tube, distance_sensor.get_distance(), chassis.getPose().x);
   pros::delay(200);

   chassis.moveToPose(tube, 15, 180, 1000, {.forwards = true, .maxSpeed = 80, .minSpeed = 70});
   chassis.waitUntilDone();

   chassis.moveToPose(tube, -5, 180, 1000, {.forwards = false});
   chassis.turnToHeading(180, 2000, {}, true);
   chassis.waitUntilDone();
   pros::delay(200);
   int goal = (chassis.getPose().x + ((distance_sensor.get_distance() - 395) / 25.4));
   pros::screen::print(pros::E_TEXT_MEDIUM, 6, "goal pos: %d, dis: %d, current: %2f", goal, distance_sensor.get_distance(), chassis.getPose().x);
   pros::delay(200);

   chassis.moveToPose(goal, -22, 180, 2000, {.forwards = false, .horizontalDrift = 2, .lead = 0.4});
   chassis.waitUntilDone();
   pros::delay(2000);

   chassis.moveToPose(30, -2, 270, 7000, {.forwards = true, .horizontalDrift = 2, .lead = 0.6, .minSpeed = 90, .earlyExitRange = 0.5});
	chassis.moveToPose(25, -60, 180, 3000, {.forwards = true, .horizontalDrift = 2, .lead = 0.5});
   chassis.turnToHeading(180, 2000);
   chassis.waitUntilDone();
}




void Autonomous::Auton1(pros::Motor intake_motor, pros::Motor hood_motor, pros::ADIDigitalOut piston, pros::Distance distance_sensor) {
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
   int tube = (chassis.getPose().x + ((distance_sensor.get_distance() - 440) / 25.4));
   pros::screen::print(pros::E_TEXT_MEDIUM, 4, "tube pos: %d, dis: %d, current: %2f", tube, distance_sensor.get_distance(), chassis.getPose().x);
   pros::delay(200);
   piston.set_value(true);
   pros::delay(200);
	chassis.moveToPose(tube, 20, 0, 1000, {.forwards = true, .maxSpeed = 80, .minSpeed = 70});
   chassis.waitUntilDone();
   chassis.moveToPoint(chassis.getPose().x, 22, 700, {.forwards = true, .minSpeed = 100});
	for(int i = 0; i<2; i++){
		chassis.moveToPoint(chassis.getPose().x, 10, 1000, {.forwards = false, .minSpeed = 70});
		chassis.moveToPoint(chassis.getPose().x, 22, 700, {.forwards = true, .minSpeed = 100});
	}
   pros::delay(2000);

   chassis.moveToPose(tube, -5, 0, 1000, {.forwards = false});
   chassis.turnToHeading(0, 2000, {}, true);
   chassis.waitUntilDone();
   pros::delay(200);
   int goal = (chassis.getPose().x + ((distance_sensor.get_distance() - 395) / 25.4));
   pros::screen::print(pros::E_TEXT_MEDIUM, 6, "goal pos: %d, dis: %d, current: %2f", goal, distance_sensor.get_distance(), chassis.getPose().x);
   pros::delay(500);
   piston.set_value(false);
	chassis.moveToPose(goal, -22, 0, 2000, {.forwards = false, .horizontalDrift = 2, .lead = 0.4});
   chassis.waitUntilDone();
   intake_motor.move_voltage(-12000);
	hood_motor.move_voltage(-12000);
   pros::delay(4000);
	intake_motor.move_voltage(0);
   hood_motor.move_voltage(0);

	chassis.moveToPose(12, -2, 270, 7000, {.forwards = true, .horizontalDrift = 2, .lead = 0.6, .minSpeed = 90, .earlyExitRange = 0.5});
	chassis.moveToPose(4, -60, 180, 3000, {.forwards = true, .horizontalDrift = 2, .lead = 0.5});
   chassis.turnToHeading(180, 2000);
   chassis.waitUntilDone();
}




void Autonomous::Auton2(pros::Motor intake_motor, pros::Motor hood_motor, pros::ADIDigitalOut piston, pros::Distance distance_sensor) {
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
   int tube = (chassis.getPose().x + ((distance_sensor.get_distance() - 440) / 25.4));
   pros::screen::print(pros::E_TEXT_MEDIUM, 4, "tube pos: %d, dis: %d, current: %2f", tube, distance_sensor.get_distance(), chassis.getPose().x);
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
   int goal = (chassis.getPose().x + ((distance_sensor.get_distance() - 395) / 25.4));
   pros::screen::print(pros::E_TEXT_MEDIUM, 6, "goal pos: %d, dis: %d, current: %2f", goal, distance_sensor.get_distance(), chassis.getPose().x);
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
   pros::screen::print(pros::E_TEXT_MEDIUM, 7, "dis: %d, current: %2f", distance_sensor.get_distance(), chassis.getPose().x);
   
   
   
   // chassis.turnToHeading(90, 2000);
   // chassis.waitUntilDone();

   // chassis.moveToPose(40.5, -125, 180, 2000, {.forwards = true, .horizontalDrift = 2});
   // chassis.moveToPoint(40.5, -100, 3000, {.forwards = false, .minSpeed = 100});
   // piston.set_value(true);
}