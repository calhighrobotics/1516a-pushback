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
        /**
         * @brief Enumeration of the different autonomous routines.
         * 
         */
        enum AUTON_ROUTINE {
            RED_LEFT,
            RED_RIGHT,
            BLUE_LEFT,
            BLUE_RIGHT,
            SKILLS
        };

        /**
         * @brief The selected autonomous routine.
         */
        static AUTON_ROUTINE auton;

        /**
         * @brief The name of the selected autonomous routine.
         */
        static std::string autonName;

        /**
         * @brief Example autonomous routine function.
         * @param intake_motor The motor used for intake.
         * @param hood_motor The motor used for the hood.
         * @param piston The pneumatic piston.
         */
        static void Auton1(pros::Motor intake_motor, pros::Motor hood_motor, pros::ADIDigitalOut piston, pros::Distance distance_sensor);
        static void Auton2(pros::Motor intake_motor, pros::Motor hood_motor, pros::ADIDigitalOut piston, pros::Distance distance_sensor);
        static void Auton3(pros::Motor intake_motor, pros::Motor hood_motor, pros::ADIDigitalOut piston, pros::Distance distance_sensor);

};
} // namespace Robot