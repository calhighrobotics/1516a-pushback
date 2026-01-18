//define fake piston class with two sinbgle actubng as double acting, extend adidevice

#include "fakePiston.hpp"
#include "api.h"

FakePiston::FakePiston(char portA, char portB) 
    : pistonA(portA), pistonB(portB) {
    _state = false; // Initially retracted
    // Constructor implementation (if needed)
}

void FakePiston::set_value(bool state) {
    if (state) {
        pistonA.set_value(true);
        pistonB.set_value(false);
    } else {
        pistonA.set_value(false);
        pistonB.set_value(true);
    }
}

void FakePiston::toggle() {
    set_value(!_state);
}