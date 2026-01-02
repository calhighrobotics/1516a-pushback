#include "auton.h"
#include "main.h" // IWYU pragma: export
#include "globals.h"

using namespace Robot;
using namespace Robot::Globals;

Autonomous::AUTON_ROUTINE Autonomous::auton = RED_LEFT;
std::string Autonomous::autonName;

ASSET(curve1_txt);

void Autonomous::Auton1(pros::Motor intake_motor, pros::Motor hood_motor, pros::adi::Pneumatics piston) {
   chassis.setPose(0,0,0);
   chassis.follow(curve1_txt, 15, 10000, true);
}