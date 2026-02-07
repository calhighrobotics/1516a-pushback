#pragma once
#include <string>
#include "api.h"
#include "pros/adi.hpp"

extern std::vector<int> distanceReset(pros::Distance front_sensor, pros::Distance left_sensor, pros::Distance right_sensor, pros::Distance back_sensor);