#pragma once
#include <string>
#include "api.h"
#include "pros/adi.hpp"
#include "main.h" // IWYU pragma: export
#include "globals.h"
#include <vector>
#include <cmath>

extern std::vector<double> getDistanceReset(bool front, bool back, bool left, bool right);