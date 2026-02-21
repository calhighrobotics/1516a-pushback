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
        //first Match load
        {-45.5, -46.5, 90, 180, 1000, 0, "INDEXER", "Point"},
        {-67, -46.5, 110, 270, 1000, 2000, "MLOADER INTAKE", "Point"},
        {-50, -46, 50, 270, 1000, 0, "REVERSE STOP", "Point"},
        //moving to blue right
        {-33, -57, 90, 290, 1000, 0, "MLOADER", "Point"},
        {30, -57, 50, 270, 2000, 0, "none", "Point"},
        {42, -41, 90, 90, 1000, 0, "none", "Point"},
        
        //score
        {19, -41.5, 110, 90, 1000, 2000, "SCORE", "Point"},
        //Match load 
        {67, -42, 110, 90, 1000, 2000, "MLOADER REVERSE INTAKE", "Point"},
        //score
        {19, -41.5, 110, 90, 1000, 2000, "SCORE REVERSE", "Point"},
        
        //moving to blue left 
        {42, -41.5, 90, 0, 1000, 0, "REVERSE MLOADER", "Point"},
        {38, 50, 70, 90, 3000, 0, "none", "Point"},
        //Match Load
        {67, 49.5, 110, 90, 1000, 2000, "MLOADER INTAKE", "Point"},
        {19, 50, 50, 90, 1000, 2000, "REVERSE MLOADER SCORE", "Point"},


        
        //moving to red left
        {33, 56, 90, 90, 2000, 0, "MLOADER", "Point"},
        {-24, 59, 120, 90, 2000, 0, "none", "Point"},
        {-42, 46, 90, 270, 1000, 0, "none", "Point"},

        //score
        {-19, 45.5, 110, 270, 1000, 2000, "SCORE", "Point"},
        //Match load
        {67, -46, 110, 270, 1000, 2000, "MLOADER REVERSE INTAKE", "Point"},
        //score
        {-19, 45.5, 110, 270, 1000, 2000, "SCORE REVERSE", "Point"},

        //moving back to parking zone
        {-42, 46, 90, 170, 1000, 0, "REVERSE MLOADER", "Point"},
        {-40, 0, 90, 270, 1000, 0, "none", "Point"},
        {-65, 0, 90, 270, 1000, 2000, "SCORE ODOM"}
    };


    std::vector<PathPoint> left = {
        //first Match load
        {39, 8, 50, 270, 1000, 0, "ODOM INDEXER", "Point"},
        {-67, -46.5, 110, 270, 1000, 2000, "MLOADER INTAKE", "Point"},
        {-50, -46, 50, 270, 1000, 0, "REVERSE STOP DIST", "Point"},
        //moving to blue right
        {-33, -56, 90, 290, 1000, 0, "MLOADER", "Point"},
        {24, -59, 50, 270, 2000, 0, "none", "Point"},
        {42, -46, 90, 90, 1000, 0, "none", "Point"},
        
        //score
        {19, -45, 110, 90, 1000, 2000, "SCORE", "Point"},
        //Match load
        {67, -46, 110, 90, 1000, 2000, "MLOADER REVERSE INTAKE DIST", "Point"},
        //score
        {19, -45, 110, 90, 1000, 2000, "SCORE REVERSE", "Point"},
        
        //moving to blue left
        {42, -45, 90, 0, 1000, 0, "REVERSE DIST MLOADER", "Point"},
        {38, 46, 70, 90, 3000, 0, "none", "Point"},
        //Match Load
        {67, 46, 110, 90, 1000, 2000, "MLOADER INTAKE", "Point"},
        {50, 46, 50, 90, 1000, 0, "REVERSE STOP DIST", "Point"},
        
        //moving to red left
        {33, 56, 90, 90, 2000, 0, "MLOADER", "Point"},
        {-24, 59, 120, 90, 2000, 0, "none", "Point"},
        {-42, 46, 90, 270, 1000, 0, "none", "Point"},

        //score
        {-19, 45, 110, 270, 1000, 2000, "SCORE", "Point"},
        //Match load
        {67, -46, 110, 270, 1000, 2000, "MLOADER REVERSE INTAKE DIST", "Point"},
        //score
        {-19, 45, 110, 270, 1000, 2000, "SCORE REVERSE", "Point"},

        //moving back to parking zone
        {-42, 46, 90, 170, 1000, 0, "REVERSE MLOADER DIST", "Point"},
        {-40, 0, 90, 270, 1000, 0, "none", "Point"},
        {-60, 0, 90, 270, 1000, 2000, "SCORE ODOM"}
    };


}
