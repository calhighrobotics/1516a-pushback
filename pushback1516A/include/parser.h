#pragma once

#include <fstream>
#include <string>
#include <vector>
#include <sstream>

enum MotionType {MOVETOPOINT, MOVETOPOSE};

struct PathPoint {
    double x, y, speed, heading;
    std::string action;
    MotionType type;
};

namespace Parser{
class Parse {
    public:
        static std::vector<PathPoint> parseJerryPath(std::string filename);
    private:
        static double getAngle(double x1, double y1, double x2, double y2);
    
};
}
