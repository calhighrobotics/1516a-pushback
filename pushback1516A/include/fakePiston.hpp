//write header file based on fakePiston.cpp

#ifndef FAKE_PISTON_HPP
#define FAKE_PISTON_HPP
#endif

#include "api.h"
#include "pros/adi.hpp"

class FakePiston {
    public:
        FakePiston(char portA, char portB);
        void set_value(bool state);
        void toggle();
    private:
        pros::adi::DigitalOut pistonA;
        pros::adi::DigitalOut pistonB;
        bool _state;
};