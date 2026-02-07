#include "distance_reset.h"
#include "main.h" // IWYU pragma: export
#include "globals.h"
#include <vector>

using namespace Robot;
using namespace Robot::Globals;


std::vector<int> distanceReset(pros::Distance front_sensor, pros::Distance left_sensor, pros::Distance right_sensor, pros::Distance back_sensor, int heading) {
    int front_distance = (front_sensor.get_distance() / 25.4) + 5; // Convert mm to inches
    int left_distance = (left_sensor.get_distance() / 25.4) + 5; // Convert mm to inches
    int right_distance = (right_sensor.get_distance() / 25.4) + 5; // Convert mm to inches
    int back_distance = (back_sensor.get_distance() / 25.4) + 7; // Convert mm to inches

    int x = 0;
    int y = 0;

    if (left_distance < right_distance) {
        int lateral = left_distance;
    } else {
        int lateral = right_distance;
    }

    if (front_distance < back_distance) {
        int vertical = front_distance;
    } else {
        int vertical = back_distance;
    }

    std::vector<int> global_position = {x, y};
    return global_position;
}

