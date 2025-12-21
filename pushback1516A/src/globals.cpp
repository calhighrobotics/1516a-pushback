#include "api.h"
#include "lemlib/api.hpp"
#include "pros/motors.h"



namespace Robot {
    namespace Globals {
        //Initialize the controller variable with the primary controller
        pros::Controller controller(pros::E_CONTROLLER_MASTER);
        

        signed char LEFT_BACK = -10;
        signed char LEFT_MID = 9;
        signed char LEFT_FRONT = -8;


        signed char RIGHT_BACK = 18;
        signed char RIGHT_MID = -19;
        signed char RIGHT_FRONT = 20;
        signed char intake_port = 5;
        signed char hood_port = 4;

        pros::Motor intake_motor(intake_port);
        pros::Motor hood_motor(hood_port);
        


        //Initialize the motor group for the left motors with ports 1, 2, and 3, denoting the blue gear cartrige
        pros::MotorGroup left({LEFT_BACK,LEFT_MID, LEFT_FRONT}, pros::v5::MotorGears::blue);

        //Initialize the motor group for the right motors with ports 4, 5, and 6, denoting the blue cartidge
        //The negative sign for the ports indicate the motors will run in reverse, as one side always must
        pros::MotorGroup right({RIGHT_BACK, RIGHT_MID, RIGHT_FRONT}, pros::v5::MotorGears::blue);
        
        //Rotation sensor ports
        uint8_t rot_sensor_horiz = 2;
        uint8_t rot_sensor_vert = 12;

        //Horizontal sensor
        pros::Rotation rotation_horiz(rot_sensor_horiz);
        lemlib::TrackingWheel horizontalTracking(&rotation_horiz, lemlib::Omniwheel::NEW_2, 0); //Distance is 0 inches from center

        //Vertical sensor
        pros::Rotation rotation_vert(rot_sensor_vert);
        lemlib::TrackingWheel verticalTracking(&rotation_vert, lemlib::Omniwheel::NEW_2, 0);

        uint8_t imu_port = 1;

        pros::Imu imu(imu_port); // imu on port 1

        lemlib::Drivetrain drivetrain(
            &left, // the left motor group
            &right, // the right motor group
            25, //25 inch track width
            lemlib::Omniwheel::NEW_325, //Wheel size
            450, // our drivetrain RPM
            0 // optimal drift value for all-omni drivetrain
        );

        lemlib::OdomSensors sensors(&verticalTracking, // vertical tracking wheel
                                    nullptr, // vertical tracking wheel 2, DNE
                                    &horizontalTracking, // horizontal tracking wheel
                                    nullptr, // horizontal tracking wheel 2, DNE
                                    &imu // inertial sensor
        );

        // Lateral (forward/backward)
        lemlib::ControllerSettings lateralPID(
            10, // kP
            0,  // kI
            20, // kD
            0,  // anti-windup
            1,  // small error range
            100, // small error timeout
            3,   // large error (inches)
            500,  // large error timeout (ms)
            5    // slew
        );

        // Angular (turning)
        lemlib::ControllerSettings angularPID(
            5,  // kP
            0,  // kI
            15, // kD
            0,  // anti-windup
            1,  // small error range
            100,// small error timeout
            3,   // large error (inches)
            500,  // large error timeout (ms)
            5    // slew
        );
        



        lemlib::ExpoDriveCurve throttleCurve(5, 12, 1.019); // deadband, minOutput, curve
        lemlib::ExpoDriveCurve steerCurve(5, 12, 1.01); // deadband, minOutput, curve

        lemlib::Chassis chassis(
            drivetrain,
            lateralPID,     // lateral PID settings
            angularPID,     // angular PID settings
            sensors,
            &throttleCurve,
            &steerCurve
        );

        // Note: do not run executable code at namespace scope. Set the chassis
        // during runtime initialization (e.g., in initialize()).

    }
}