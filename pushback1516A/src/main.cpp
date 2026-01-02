#include "main.h"
#include "globals.h"
#include "lemlib/api.hpp"
#include "pros/misc.h"
#include "pros/motors.h"
#include "auton.h"


using namespace Robot::Globals;
using namespace Robot;


/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	
	//Basic intitialization of the screen
	pros::lcd::initialize();


	pros::lcd::print(0, "Calibrating IMU...");

	pros::lcd::set_text(1, "Team 1516A");
	//Add button to screen
	pros::lcd::register_btn1_cb(on_center_button);

	chassis.calibrate();
	chassis.setPose({0, 0, 0});

	// Configure motor brake mode based on brakeMode

}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */

ASSET(curve1_txt);
void autonomous() {
	chassis.setPose(0,0,0);
	pros::lcd::print(0, "x: %.2f y: %.2f theta: %.2f", chassis.getPose().x, chassis.getPose().y, chassis.getPose().theta);
	chassis.moveToPose(0,-11, 0, 2000, {.minSpeed=72, .earlyExitRange=3});
	pros::lcd::print(0, "x: %.2f y: %.2f theta: %.2f", chassis.getPose().x, chassis.getPose().y, chassis.getPose().theta);
	chassis.moveToPose(-10, 23, 40, 3000);
	pros::lcd::print(0, "x: %.2f y: %.2f theta: %.2f", chassis.getPose().x, chassis.getPose().y, chassis.getPose().theta);
}	

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
	bool piston_state = false;
	bool descore_state = false;
	bool button_pressed = false;
	bool button_pressed2 = false;
	chassis.setPose(0, 0, 0);

	while (true) {
		//Drivetrain Block
		#pragma region 
		pros::lcd::print(0, "x: %.2f y: %.2f theta: %.2f", chassis.getPose().x, chassis.getPose().y, chassis.getPose().theta);
		chassis.arcade(controller.get_analog(ANALOG_LEFT_Y), controller.get_analog(ANALOG_RIGHT_X));
		pros::lcd::print(2, "arcade mode");
		//Brake Mode Control
		if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
            chassis.setBrakeMode(pros::E_MOTOR_BRAKE_BRAKE);
			pros::lcd::print(1, "brake mode");
        }
		else{
			chassis.setBrakeMode(pros::E_MOTOR_BRAKE_COAST);
			pros::lcd::print(1, "coast mode");
		}

		//Intake and Hood control
		
		if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
			intake_motor.move_voltage(-12000);
			hood_motor.move_voltage(-12000);
		}
		else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
			intake_motor.move_voltage(-12000);
		}

		else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_X)) {
			intake_motor.move_voltage(12000);
			hood_motor.move_voltage(12000);
		}
		else {
			intake_motor.move_voltage(0);
			hood_motor.move_voltage(0);
		}

		if (!controller.get_digital(pros::E_CONTROLLER_DIGITAL_B) && button_pressed) {
			if (piston_state) {
				pros::lcd::print(3, "closing piston");
				piston.set_value(false);
				piston_state = false;
			}
			else {
				pros::lcd::print(3, "opening piston");
				piston.set_value(true);
				piston_state = true;
			}
		}
		if (!controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2) && button_pressed2) {
			if (descore_state) {
				pros::lcd::print(5, "closing descore");
				descore.set_value(false);
				descore_state = false;
			}
			else {
				pros::lcd::print(5, "opening descore");
				descore.set_value(true);
				descore_state = true;
			}
		}

		button_pressed = controller.get_digital(pros::E_CONTROLLER_DIGITAL_B);
		button_pressed2 = controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2);

	#pragma endregion
		//Autonomous Test Block
		// pros::lcd::print(0, "x: %.2f y: %.2f theta: %.2f", chassis.getPose().x, chassis.getPose().y, chassis.getPose().theta);
		// chassis.turnToHeading(180, 10000, {}, true);
		pros::delay(50);                           // Run for 100 ms then update
	}
}