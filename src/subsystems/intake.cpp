#include "subsystems/intake.hpp"

okapi::Motor intake = okapi::Motor(7);
okapi::ControllerButton l1 = okapi::ControllerButton(okapi::ControllerDigital::L1, false);

void intakeStep(okapi::Motor motor, int &intakeState, okapi::ControllerButton r1) { //TODO: when l1 held intake, when l2 held outtake, when l1+l2 pressed toggle to hold (low rpm)
    if (l1.changed() == true) {
        intakeState++;
        if (intakeState == 1) {
            motor.moveVelocity(200);
        } else if (intakeState == 3) {
            motor.moveVelocity(0);
        } else if (intakeState == 4) {
            intakeState = 0;
		}
    }
}