#include "distance_reset.h"
#include "main.h" // IWYU pragma: export
#include "globals.h"
#include <vector>

using namespace Robot;
using namespace Robot::Globals;


std::vector<int> distanceReset(pros::Distance left_sensor, pros::Distance right_sensor, pros::Distance back_sensor) {
    int left_distance = (left_sensor.get_distance() / 25.4) + 5; // Convert mm to inches
    int right_distance = (right_sensor.get_distance() / 25.4) + 5; // Convert mm to inches
    int back_distance = (back_sensor.get_distance() / 25.4) + 7; // Convert mm to inches

    int x = 0;
    int y = 0;

    if (left_distance < right_distance) {
        x = 45 - (right_distance/25.4); // Assuming field width is 45 inches
    } else {
        x = 45 - (left_distance/25.4); // Assuming field width is 45 inches
    }

    y = 45 - (back_distance/25.4); // Assuming field length is 45 inches

    std::vector<int> global_position = {x, y};
    return global_position;
}

