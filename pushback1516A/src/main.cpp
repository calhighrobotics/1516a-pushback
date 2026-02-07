#include "main.h"
#include "globals.h"
#include "lemlib/api.hpp"
#include "pros/misc.h"
#include "pros/motors.h"
#include "auton.h"
#include "parser.h"
#include "screen/selector.hpp"

using namespace Robot::Globals;
using namespace Robot;

struct Systems {
	selector_screen sel;
} systems;

/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button()
{
	static bool pressed = false;
	pressed = !pressed;
	if (pressed)
	{
		pros::lcd::set_text(2, "I was pressed!");
	}
	else
	{
		pros::lcd::clear_line(2);
	}
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize()
{

	// Basic intitialization of the screen
	pros::lcd::initialize();
	// Add button to screen
	pros::lcd::register_btn1_cb(on_center_button);

    systems.sel.selector();

	chassis.calibrate();
	chassis.setPose(0, 0, 0);

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

void autonomous()
{
// 	left.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
// 	right.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
// 	odom_lifter.set_value(false); // keep odom lifter up
// 	mloader.set_value(true);
// 	chicken_wing.set_value(true);

// 	pros::delay(500);
	
//     chassis.setPose(0, 0, 0);
    
//    // Add autonomous actions here
//     chassis.moveToPoint(0, 12, 10000);

// 	chassis.waitUntilDone();

// 	while (true) {
// 		pros::delay(20);
// 		pros::lcd::print(0, "Tick Position: %ld", rotation_vert.get_position());
// 		pros::lcd::print(1, "x: %.2f, y: %.2f theta: %.2f", chassis.getPose().x, chassis.getPose().y, chassis.getPose().theta);
// 	}

	std::vector<PathPoint> path = Parser::Parse::parseJerryPath("src\\test.txt");

	pros::screen::print(TEXT_MEDIUM, 1, "size: %d", path.size());

	
	Autonomous::AutoDrive(intake_motor, hood_motor, mloader, odom_lifter, chicken_wing, indexer, extender, back_sensor, left_sensor, right_sensor);


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
void opcontrol()
{
	bool mloader_state = false;
	bool chicken_wing_state = false;
	bool indexer_state = true;
	double bias = 0.0;
	chassis.setPose(0, 0, 0);	

	//odom_lifter.set_value(true); // keep odom lifter up
	mloader.set_value(false);
	chicken_wing.set_value(false);
	indexer.set_value(true);
	extender.set_value(true);

// 	pros::delay(200);

// 	chassis.setPose(0, 0, 0);
    
//    // Add autonomous actions here
//     chassis.turnToHeading(180, 1000, {.direction = AngularDirection::CCW_COUNTERCLOCKWISE, .maxSpeed = 80});

// 	chassis.waitUntilDone();
// 	//pros::lcd::initialize();

// 	while (true) {
// 		pros::delay(20);
// 		pros::screen::print(TEXT_MEDIUM, 3, "Tick Position: %ld", rotation_vert.get_position()/100);
// 		pros::screen::print(TEXT_MEDIUM, 0, "x: %.2f y: %.2f theta: %.2f", chassis.getPose().x, chassis.getPose().y, chassis.getPose().theta);
// 	}

	while (true) {
		// Drivetrain Block
		#pragma region 

				pros::screen::print(TEXT_MEDIUM, 0, "x: %.2f y: %.2f theta: %.2f", chassis.getPose().x, chassis.getPose().y, chassis.getPose().theta);

				controller.print(0, 0, "left 1: %2f, right 1: %2f", left_front.get_temperature(), right_front.get_temperature());
				controller.print(1, 0, "left 2: %2f, right 2: %2f", left_mid.get_temperature(), right_mid.get_temperature());
				controller.print(2, 0, "left 3: %2f, right 3: %2f", left_back.get_temperature(), right_back.get_temperature());
				pros::screen::print(TEXT_MEDIUM, 7, "intake: %2f, hood: %2f", intake_motor.get_temperature(), hood_motor.get_temperature());

				pros::screen::print(TEXT_MEDIUM, 1, "left 1: %2f, right 1: %2f", left_front.get_temperature(), right_front.get_temperature());
				pros::screen::print(TEXT_MEDIUM, 2, "left 2: %2f, right 2: %2f", left_mid.get_temperature(), right_mid.get_temperature());
				pros::screen::print(TEXT_MEDIUM, 3, "left 3: %2f, right 3: %2f", left_back.get_temperature(), right_back.get_temperature());
				chassis.arcade(controller.get_analog(ANALOG_LEFT_Y), controller.get_analog(ANALOG_RIGHT_X));
				//pros::lcd::print(2, "arcade mode");
				
				// Brake Mode Control
				if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1))
				{
					chassis.setBrakeMode(pros::E_MOTOR_BRAKE_BRAKE);
				}
				else
				{
					chassis.setBrakeMode(pros::E_MOTOR_BRAKE_COAST);
				}
				// Intake and Hood control

				if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1))
				{
					intake_motor.move_voltage(-12000);
					hood_motor.move_voltage(-12000);
				}
				else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2))
				{
					intake_motor.move_voltage(-12000);
					hood_motor.move_voltage(1000);
				}

				else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_X))
				{
					intake_motor.move_voltage(12000);
					hood_motor.move_voltage(12000);
				}
				else
				{
					intake_motor.move_voltage(0);
					hood_motor.move_voltage(0);
				}

				if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B))
				{
					mloader.set_value(!mloader_state);
					mloader_state = !mloader_state;
				}

				if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2))
				{
					chicken_wing.set_value(true);
				}
				else{
					chicken_wing.set_value(false);
				}
				if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A))
				{
					indexer.set_value(!indexer_state);
					indexer_state = !indexer_state;
				}

				// if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_Y))
				// {
				// 	puncher.set_value(true); // fire puncher
				// 	mloader.set_value(false); // retract mloader to avoid jamming
				// 	mloader_state = false;
				// }

				//button_pressed = controller.get_digital(pros::E_CONTROLLER_DIGITAL_B);
				//button_pressed2 = controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2);

				pros::delay(20);

	#pragma endregion
	}

}