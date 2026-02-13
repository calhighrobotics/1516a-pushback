#pragma once

#include <fstream>
#include <string>
#include <vector>
#include <sstream>

struct PathPoint {
    double x, y, speed, heading, timeout, delay;
    std::string action, type;
};

namespace Paths {
    std::vector<PathPoint> skills = {
        {-59, -34, 50, 170, 1000, 0, "ODOM", "Point"},
        {-32, -13, 50, 235, 1000, 0, "REVERSE", "Point"}, 
        {-13, -13, 50, 225, 1000, 0, "INDEXER", "Point"},
        {-18.5, -19, 70, 225, 1000, 0, "REVERSE", "Chained"},
        {-28, -32, 70, 225, 1000, 0, "MLOADER", "Chained"},
        {-38, -46.5, 70, 270, 1000, 0, "none", "Pose"}
    };
}
