#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>

#include "parser.h"
#include "main.h" // IWYU pragma: export
#include "globals.h"

using namespace Robot;
using namespace Robot::Globals;

namespace Parser{
    double Parse::getAngle(double x1, double y1, double x2, double y2) {
        return atan2(x2 - x1, y2 - y1) * (180.0 / M_PI);
    }
    
    std::vector<PathPoint> Parse::parseJerryPath(std::string filename) {
        std::vector<PathPoint> pathPoints;

        pathPoints.push_back({chassis.getPose().x, chassis.getPose().y, 0, chassis.getPose().theta, "", MOVETOPOINT}); // Default first point to prevent errors with actions on the first point

        std::ifstream file(filename);
    
        bool recording = false;
    
        if (!file.is_open()) {
            return pathPoints;
        }
        
        std::string line;
        while (std::getline(file, line)) {
            if (line.find("#PATH-POINTS-START") != std::string::npos) { recording = true; continue; }
            if (line.find("#PATH-POINTS-END") != std::string::npos) { recording = false; break; }
    
            if (recording) {
                if (line.find("#INTAKE") != std::string::npos && !pathPoints.empty()) {
                    if (!pathPoints.empty()) {
                        pathPoints.back().action = "INTAKE";
                    }
                    continue;
                }
                else if (line.find("#SCORE") != std::string::npos && !pathPoints.empty()) {
                    if (!pathPoints.empty()) {
                        pathPoints.back().action = "SCORE";
                    }
                    continue;
                }   
                else if (line.find("#STOP") != std::string::npos && !pathPoints.empty()) {
                    if (!pathPoints.empty()) {
                        pathPoints.back().action = "STOP";
                    }
                    continue;
                }
                else if (line.find("#ODOM") != std::string::npos && !pathPoints.empty()) {
                    if (!pathPoints.empty()) {
                        pathPoints.back().action = "ODOM";
                    }
                    continue;
                }
                else if (line.find("#INDEXER") != std::string::npos && !pathPoints.empty()) {
                    if (!pathPoints.empty()) {
                        pathPoints.back().action = "INDEXER";
                    }
                    continue;
                }
                else if (line.find("#MLOADER") != std::string::npos && !pathPoints.empty()) {
                    if (!pathPoints.empty()) {
                        pathPoints.back().action = "MLOADER";
                    }
                    continue;
                }
                else if (line.find("#WING") != std::string::npos && !pathPoints.empty()) {
                    if (!pathPoints.empty()) {
                        pathPoints.back().action = "WING";
                    }
                    continue;
                }
            }
    
            if (recording && !line.empty()) {
                std::istringstream ss(line);
                PathPoint point;
                std::string val;
    
                std::vector <double> values;
    
                while (std::getline(ss, val, ',')) {
                    try {
                        values.push_back(std::stod(val));
                    } catch (...) {
                        // Handle the case where conversion fails
                        continue;
                    }
                }
                
                if (values.size() >= 3) {
                    point.x = values[0];
                    point.y = values[1];
                    point.speed = values[2];
                    point.heading = 0.0;
                    point.type = MotionType::MOVETOPOINT;
                    pathPoints.push_back(point);
                }
            }
        }
    
        for (int i = 1; i < pathPoints.size(); i++) {
            if (i < pathPoints.size() - 1) {
                pathPoints[i].heading = getAngle(pathPoints[i].x, pathPoints[i].y, pathPoints[i+1].x, pathPoints[i+1].y);
            } else {
                pathPoints[i].heading = pathPoints[i-1].heading; // Keep the last point's heading the same as the previous one
            }
    
            if (i > 0 && std::abs(pathPoints[i].heading - pathPoints[i-1].heading) > 10) {
                pathPoints[i].type = MotionType::MOVETOPOSE;
            }
    
        }
        return pathPoints;
    }
}