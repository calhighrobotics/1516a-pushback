#include "robot/auton.h"
#include "main.h" // IWYU pragma: export
#include "globals.h"

using namespace Robot;
using namespace Robot::Globals;


// Define your autonomous routines here
void Autonomous::Auton1() {
    // Example autonomous routine 1
    chassis.moveDistance(24_in); // Move forward 24 inches
    chassis.turnAngle(90_deg);   // Turn 90 degrees
    chassis.moveDistance(12_in); // Move forward 12 inches
}