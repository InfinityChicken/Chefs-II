#include "subsystems/messaging.hpp"

void overheat(okapi::Motor motors[8], okapi::Controller controller) {
    string msg = "Overheat: None";
    for(int i=0; i<8; i++) {
        if(motors[i].isOverTemp()) {
            msg = "Overheat: " + to_string(motors[i].getPort()) + " ";
        }
    }
    controller.setText(0, 0, msg);
}