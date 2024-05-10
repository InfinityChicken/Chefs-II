#include "subsystems/messaging.hpp"

okapi::ControllerButton x = okapi::ControllerButton(okapi::ControllerDigital::X, false);

void overheat(okapi::Motor motors[8], okapi::Controller &controller, okapi::ControllerButton &x) {
    if(x.changedToPressed()) {
        string msg = "Overheat: None";
        for(int i=0; i<8; i++) { //checks all the motors every tick for overheating and tells the driver if the motor is overheating
            if(motors[i].isOverTemp()) { msg = "Overheat: " + to_string(motors[i].getPort()) + " "; }
        }
        controller.setText(0, 0, msg);
    }
}