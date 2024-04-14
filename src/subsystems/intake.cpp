#include "include/subsystems/intake.hpp"

okapi::Motor intake = okapi::Motor(7);
okapi::ControllerButton l1 = okapi::ControllerButton(okapi::ControllerDigital::L1, false); //I FIGURED OUT HOW TO USE THE :: THING I DESERVE A STANDING OVATION
int8_t intakeState;

void intakeStep(okapi::Motor motor, int &intakeState) {
    intakeState++;
    if (intakeState == 1) {
        motor.moveVelocity(200);
    } else if (intakeState == 3) {
        motor.moveVelocity(0);
    } else if (intakeState == 4) {
        intakeState = 0;
    }
}