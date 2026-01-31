#pragma once
#include <string>
#include "api.h"
#include "pros/adi.hpp"

namespace Robot {
/**
 * @details We use Lemlib extensively for our documentation. You can find the documentation for Lemlib at
 * <A HREF="https://lemlib.github.io/lemlib/">Lemlib documentation</A>.
 * @brief The \ref Autonomous class contains classes and functions related to the robot's autonomous behavior.
 */
class Autonomous {
    public:
        enum AUTON_ROUTINE { RED_LEFT = 1, RED_RIGHT = 2, BLUE_LEFT = -1, BLUE_RIGHT = -2, SKILLS = 0};

        /**
            * @brief Sets the number of the autonomous program to use.
            *
            * This function allows the user to specify the autonomous program to be executed by the robot.
            * The autonomous program number determines the specific actions and movements the robot will perform.
            *
            * @param auton The number of the autonomous program to use.
            */
        static AUTON_ROUTINE auton;

        /**
            * @brief The name of the autonomous program.
            * @details This variable stores the name of the autonomous program currently
            * selected. It is handled by the switching functions and the screen.
            */
        static std::string autonName;

        /**
            * @brief Drives the robot autonomously.
            *
            * This function drives the robot autonomously based on the selected
            * autonomous program. It takes a reference to a Puncher object and a boolean
            * value indicating whether to use autonomous mode.
            *
            * @param puncher A reference to the Puncher object.
            * @param autono A boolean value indicating whether to use autonomous mode.
            */
        static  void AutoDrive(pros::Motor intake_motor, pros::Motor hood_motor, pros::ADIDigitalOut piston, pros::ADIDigitalOut odom_lifter, pros::ADIDigitalOut descore, pros::ADIDigitalOut indexer, pros::ADIDigitalOut extender, pros::Distance back_sensor, pros::Distance left_sensor, pros::Distance right_sensor);

        /**
            * @brief Switches the autonomous program.
            *
            *
            * This function switches the autonomous program to the next available
            * program. It allows the user to cycle through different autonomous programs
            * during runtime.
            */
        static void AutonSwitcher(int autonNum);

    private:
        /**
         * @brief Enumeration of the different autonomous routines.
         * 
         */


        /**
         * @brief The selected autonomous routine.
         */
        /**
         * @brief The name of the selected autonomous routine.
         */ 

        /**
         * @brief Example autonomous routine function.
         * @param intake_motor The motor used for intake.
         * @param hood_motor The motor used for the hood.
         * @param piston The pneumatic piston.
         */
        static void Auton1(pros::Motor intake_motor, pros::Motor hood_motor, pros::ADIDigitalOut piston, pros::ADIDigitalOut odom_lifter, pros::ADIDigitalOut descore, pros::ADIDigitalOut indexer, pros::ADIDigitalOut extender, pros::Distance back_sensor, pros::Distance left_sensor, pros::Distance right_sensor);
        static void Auton2(pros::Motor intake_motor, pros::Motor hood_motor, pros::ADIDigitalOut piston, pros::ADIDigitalOut odom_lifter, pros::ADIDigitalOut descore, pros::ADIDigitalOut indexer, pros::ADIDigitalOut extender, pros::Distance back_sensor, pros::Distance left_sensor, pros::Distance right_sensor);
        static void Auton3(pros::Motor intake_motor, pros::Motor hood_motor, pros::ADIDigitalOut piston, pros::ADIDigitalOut odom_lifter, pros::ADIDigitalOut descore, pros::ADIDigitalOut indexer, pros::ADIDigitalOut extender, pros::Distance back_sensor, pros::Distance left_sensor, pros::Distance right_sensor);
        static void Auton4(pros::Motor intake_motor, pros::Motor hood_motor, pros::ADIDigitalOut piston, pros::ADIDigitalOut odom_lifter, pros::ADIDigitalOut descore, pros::ADIDigitalOut indexer, pros::ADIDigitalOut extender, pros::Distance back_sensor, pros::Distance left_sensor, pros::Distance right_sensor);



};
} // namespace Robot