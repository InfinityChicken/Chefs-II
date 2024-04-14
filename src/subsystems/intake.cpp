#include "subsystems/intake.hpp"

okapi::Motor intake = okapi::Motor(7);
okapi::ControllerButton l1 = okapi::ControllerButton(okapi::ControllerDigital::L1, false);

void intakeStep(okapi::Motor motor, int &intakeState) {
    intakeState++;
    if (intakeState == 1) {
        motor.moveVelocity(200); //TODO is it supposed to be negative or positive voltage i think it's positive but idrk
    } else if (intakeState == 3) {
        motor.moveVelocity(0);
    } else if (intakeState == 4) {
        intakeState = 0;
    }
}