#pragma once

#include <fstream>
#include <string>
#include <vector>
#include <sstream>

/*                 ACTIONS
    - INTAKE: intakes until delay ends
    - STOP: useless don't use or pay attention to it
    - ODOM: useless don't use or pay attention to it
    - INDEXER: toggles indexer
    - MLOADER: toggles mloader
    - EXTENDER: toggles extender
    - REVERSE: toggles reversing bot direction
    - SCORE: turns on intake and intake hood for delay seconds
        the only action that runs after movement
    - DIST: don't use

                    TYPES
    - Point: turns to point set (timeout/2),
        moves to point set(timeout), turns 
        to heading (timeout/1.5)
    - Chained: a moveToPose you can chain to a
        Pose or Chained, or Point
    - Pose: a move to pose
    - SwingLEFT/SwingRIGHT: swings to either side
*/


struct PathPoint {
    double x, y, speed, heading, timeout, delay;
    std::string action, type;
};


namespace Paths {
    std::vector<PathPoint> skills = {
        //first Match load
        {-45.5, -47.5, 50, 270, 2000, 0, "INDEXER", "Point"},
        {-62, -51.5, 50, 270, 1000, 2000, "MLOADER INTAKE ", "Point"},
        {-45.5, -51.5, 50, 270, 1000, 0, "REVERSE STOP", "Point"},
        //moving to blue right
        {-33, -68, 50, 270, 1000, 0, "MLOADER", "Point"},
        {40, -68, 90, 245, 2500, 0, "none", "Point"},
        {42, -50, 50, 90, 1000, 0, "none", "Point"},
        
        //score
        {19, -50, 50, 90, 1000, 2000, "SCORE", "Point"},
        //Match load 
        {67, -50.5, 50, 90, 1000, 2000, "MLOADER REVERSE INTAKE", "Point"},
        //score
        {19, -50, 50, 90, 1000, 2000, "SCORE REVERSE", "Point"},
        
        //moving to blue left 
        {42, -50, 90, 0, 1000, 0, "REVERSE MLOADER", "Point"},
        {38, 40, 70, 90, 3000, 0, "none", "Point"},
        //Match Load
        {67, 44, 50, 90, 1000, 2000, "MLOADER INTAKE", "Point"},

        //score
        {19, 44.5, 50, 90, 1000, 2000, "REVERSE MLOADER SCORE", "Point"},


        
        // //moving to red left
        // {33, 56, 90, 90, 2000, 0, "MLOADER", "Point"},
        // {-24, 59, 120, 90, 2000, 0, "none", "Point"},
        // {-42, 46, 90, 270, 1000, 0, "none", "Point"},

        // //score
        // {-19, 45.5, 110, 270, 1000, 2000, "SCORE", "Point"},
        // //Match load
        // {67, -46, 110, 270, 1000, 2000, "MLOADER REVERSE INTAKE", "Point"},
        // //score
        // {-19, 45.5, 110, 270, 1000, 2000, "SCORE REVERSE", "Point"},

        // //moving back to parking zone
        // {-42, 46, 90, 170, 1000, 0, "REVERSE MLOADER", "Point"},
        // {-40, 0, 90, 270, 1000, 0, "none", "Point"},
        // {-65, 0, 90, 270, 1000, 2000, "SCORE ODOM"}
    };


    std::vector<PathPoint> left = {
        //intake first three and and score mid goal
        {39, -8, 50, 270, 500, 0, "INDEXER", "Point"},
        {21, -21, 50, 135, 1000, 0, "INTAKE", "Point"},
        //midgoal
        {6.5, -6.5, 50, 135, 2000, 1000, "REVERSE  MLOADER INDEXER SCORE", "Point"},
        //move to matchload
        {40, -43.5, 50, 90, 3000, 0, "REVERSE MLOADER INDEXER", "Point"},
        //matchload
        {66, -46.5, 110, 90, 300, 500, "INTAKE MLOADER", "Point"},
        //long goal
        {15, -45.5, 50, 90, 1000, 2000, "REVERSE MLOADER SCORE", "Point"},
        //wing
        {30, -45.5, 50, 45, 1000, 0, "REVERSE", "Point"},
        {38.5, -39, 50, 90, 1000, 0, "none", "Point"},
        {5, -36, 50, 90, 2000, 0, "REVERSE", "Point"},
    };

    std::vector<PathPoint> leftElims = {
        //intake first three
        {39, -8, 50, 270, 500, 0, "INDEXER", "Point"},
        {21, -21, 50, 135, 700, 0, "INTAKE", "Point"},
        //move to matchload
        {40, -43.5, 50, 90, 3000, 0, "none", "Point"},
        //matchload
        {70, -46.5, 110, 90, 1000, 500, "INTAKE MLOADER", "Point"},
        //score long goal
        {13, -45.5, 50, 90, 1000, 2000, "REVERSE MLOADER SCORE", "Point"},
        //wing
        {30, -45.5, 50, 45, 1000, 0, "REVERSE", "Point"},
        {38.5, -39, 50, 90, 1000, 0, "none", "Point"},
        {5, -36, 50, 90, 2000, 0, "REVERSE", "Point"},
    };

    std::vector<PathPoint> right = {
        //intake first three
        {39, 8, 50, 270, 500, 0, "INDEXER", "Point"},
        {20, 20, 50, 45, 1200, 0, "INTAKE", "Point"},
        //move to matchload
        {40, 47.5, 50, 90, 3000, 0, "none", "Point"},
        //matchload
        {70, 51.5, 110, 90, 1000, 500, "INTAKE MLOADER", "Point"},
        //score long goal
        {13, 50.5, 50, 90, 1000, 2000, "REVERSE MLOADER SCORE", "Point"},
        //wing
        {30, 50.5, 50, 135, 1000, 0, "REVERSE", "Point"},
        {38.5, 36.5, 50, 270, 1000, 0, "none", "Point"},
        {5, 35, 50, 270, 2000, 0, "none", "Point"},
    };

    std::vector<PathPoint> awp = {
        //LEFT
        //intake first three and and score mid goal
        {39, -8, 50, 270, 500, 0, "INDEXER", "Point"},
        {21, -21, 50, 135, 1000, 0, "INTAKE", "Point"},
        //midgoal
        {6.5, -6.5, 50, 135, 2000, 1000, "REVERSE  MLOADER INDEXER SCORE", "Point"},
        //move to matchload
        {40, -43.5, 50, 90, 3000, 0, "REVERSE MLOADER INDEXER", "Point"},
        //matchload
        {66, -46.5, 110, 90, 300, 500, "INTAKE MLOADER", "Point"},
        //long goal
        {15, -45.5, 50, 90, 1000, 2000, "REVERSE MLOADER SCORE", "Point"},

        //RIGHT
        //move to other side + intake first three
        {30, -45.5, 50, 180, 1000, 0, "REVERSE", "Point"},
        {20, 20, 90, 45, 3000, 0, "INTAKE", "Point"},

        //move to matchload
        {40, 47.5, 50, 90, 3000, 0, "none", "Point"},
        //matchload
        {70, 51.5, 110, 90, 1000, 500, "INTAKE MLOADER", "Point"},
        //score long goal
        {13, 50.5, 50, 90, 1000, 2000, "REVERSE MLOADER SCORE", "Point"},
        //wing
        {30, 50.5, 50, 135, 1000, 0, "REVERSE", "Point"},
        {38.5, 36.5, 50, 270, 1000, 0, "none", "Point"},
        {5, 35, 50, 270, 2000, 0, "none", "Point"},
    };

}
