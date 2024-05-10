#include "subsystems/messaging.hpp"

using std::vector;

okapi::ControllerButton x = okapi::ControllerButton(okapi::ControllerDigital::X, false);

void overheat(vector<okapi::Motor>& motors, okapi::Controller controller, okapi::ControllerButton x) {
   
   if(x.changedToPressed()) {
        string msg = "Overheat: None";
        for(int i=0; i<8; i++) { //checks all the motors every tick for overheating and tells the driver if the motor is overheating
            if(motors[i].isOverTemp()) { msg = "Overheat: " + to_string(motors[i].getPort()) + " "; }
        }
        controller.clearLine(0);

        controller.setText(0, 0, msg);
    }
}