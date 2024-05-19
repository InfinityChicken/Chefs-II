#include "subsystems/slapper.hpp"
#include "subsystems/drivetrain.hpp"

okapi::Motor slapper = okapi::Motor(12); //TODO: find proper motor direction
okapi::ControllerButton r1 = okapi::ControllerButton(okapi::ControllerDigital::R1, false);

void slapperStep(int &slapperState, bool &driveDisabled) {
    if (r1.changedToPressed() == true) {
        slapperState++;
        if (slapperState == 2) {
            slapper.moveVelocity(0);
            slapperState = 0;
            driveDisabled = false;
        }
    }

    if (slapperState == 1) { //if the slapper is activated,
        driveDisabled = true; //the input to the drive is turned off
        drivetrain->getModel()->tank(0,0);
        slapper.moveVelocity(200 * (1 - abs ( controller.getAnalog(okapi::ControllerAnalog::rightY) ) ) ); //and the motor gets constantly updated with speed
        //at neutral, the motor will move at max speed (200*(1-0) rpm), but at max delay (joystick throttled), the motor will move at (200*(1-1) rpm).
        //assuming that getAnalog returns a value from 0-1, if it doesn't this code is cooked
    }
}