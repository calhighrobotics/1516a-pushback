#include "distance_reset.h"
#include "main.h" // IWYU pragma: export
#include "globals.h"
#include <vector>
#include <cmath>
#include <string>

using namespace Robot;
using namespace Robot::Globals;


#include <vector>
#include <cmath>

std::vector<double> getDistanceReset(bool front, bool back, bool left, bool right) {
    lemlib::Pose currentPose = chassis.getPose();
    // Convert heading to Radians and wrap it to 0-2PI
    double theta = currentPose.theta * (M_PI / 180.0);

    // 1. SENSOR POSITIONS (Relative to your new tracking center)
    // If the front sensor is 5" ahead of the center: {5.0, 0.0}
    // If the left sensor is 6" left of the center: {0.0, -6.0}
    struct Sensor { pros::Distance* s; double offsetX; double offsetY; double angleOffset; std::string name; bool active;};
    
    // Define your 4 sensors with their local coordinates
    // offset is not correct in direction that does not matter if you do 90 degree turns
    std::vector<Sensor> sensors = {
        {&front_sensor,  -4.0,  -4.0, 0, "Front", front},            // Front
        {&back_sensor,  8.0,  8.0, M_PI, "Back", back},         // Back (rotated 180)
        {&left_sensor,   7.5,  7.5, M_PI / 2.0, "Left", left},   // Left (rotated 90)
        {&right_sensor,  7.0,  7.0, -M_PI / 2.0, "Right", right}   // Right (rotated -90)
    };

    double newX = currentPose.x;
    double newY = currentPose.y;

    for (auto& sensor : sensors) {
        double distMM = sensor.s->get_distance();
        if (distMM == 0 || distMM > 2000) continue; // Skip if out of range or error

        double distInch = distMM / 25.4;
        // Global angle the sensor is pointing
        double globalSensorAngle = theta + sensor.angleOffset;

        // Components of the sensor's direction vector
        double cosA = cos(globalSensorAngle);
        double sinA = sin(globalSensorAngle);

        // Check if sensor is facing a wall (within ~5 degrees of cardinal directions)
        // Adjusting X (Facing Left or Right)
        if (std::abs(sinA) > 0.99 && sensor.active) { 
            // Facing Right (+X)
            if (currentPose.x > 0) newX = 72.0 - (distInch + sensor.offsetY);
            // Facing Left (-X)
            else newX = -72.0 + (distInch + std::abs(sensor.offsetY));

            pros::screen::print(pros::E_TEXT_MEDIUM, 4, "Sensor %s: X: %.2f", sensor.name, newX);
        }
        
        // Adjusting Y (Facing Front or Back)
        if (std::abs(cosA) > 0.99 && sensor.active) {
            // Facing Up (+Y)
            if (currentPose.y > 0) newY = 72.0 - (distInch + sensor.offsetX);
            // Facing Down (-Y)
            else newY = -72.0 + (distInch + std::abs(sensor.offsetX));

            pros::screen::print(pros::E_TEXT_MEDIUM, 5, "Sensor %s: Y: %.2f", sensor.name, newY);
        }
    }

    return std::vector<double>{newX, newY, currentPose.theta};
}
