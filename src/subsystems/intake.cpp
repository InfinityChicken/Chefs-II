#include "subsystems/intake.hpp"

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