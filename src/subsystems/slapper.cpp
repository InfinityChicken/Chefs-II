#include "subsystems/slapper.hpp"

okapi::Motor slapper = okapi::Motor(8); //TODO: find proper motor direction
okapi::ControllerButton r1 = okapi::ControllerButton(okapi::ControllerDigital::R1, false);

void slapperStep(okapi::Motor &motor, int &slapperState, okapi::ControllerButton &r1, bool &driveDisabled, okapi::Controller &controller) {
    if (r1.changed() == true) {
        slapperState++;
        if (slapperState == 3) {
            motor.moveVelocity(0);
            driveDisabled = false; //if the slapper is deactivated, drive input turns back on
        } else if (slapperState == 4) {
            slapperState = 0; //and then the code gets reset
        }
    }

    if (slapperState == 1||2) { //if the slapper is activated,
        driveDisabled = true; //the input to the drive is turned off
        motor.moveVelocity(200 * (1 - abs ( controller.getAnalog(okapi::ControllerAnalog::rightY) ) ) ); //and the motor gets constantly updated with speed
        //at neutral, the motor will move at max speed (200*(1-0) rpm), but at max delay (joystick throttled), the motor will move at (200*(1-1) rpm).
        //assuming that getAnalog returns a value from 0-1, if it doesn't this code is cooked
    }

    //should i be proud or disappointed in this
}