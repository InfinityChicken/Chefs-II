#include "subsystems/intake.hpp"

okapi::Motor intake = okapi::Motor(7);
okapi::ControllerButton l1 = okapi::ControllerButton(okapi::ControllerDigital::L1, false);
okapi::ControllerButton l2 = okapi::ControllerButton(okapi::ControllerDigital::L2, false);

void intakeStep(okapi::Motor motor, okapi::ControllerButton l1, okapi::ControllerButton l2, bool &hold) {
    if (l1.changedToPressed() && !l2.isPressed()) {
        motor.moveVelocity(200);
        hold = false;
    }

    if (l2.changedToPressed() && !l1.isPressed()) {
        motor.moveVelocity(-200);
        hold = false;
    }

    if ((l1.isPressed() && l2.changedToPressed()) || (l1.changedToPressed() && l2.changedToPressed())) {
        if (hold == false) {
            motor.moveVelocity(100);
            hold = true;
        }
        if (hold == true) {
            motor.moveVelocity(0);
            hold = false;
        }
    }

    if ((!l1.isPressed() || !l2.isPressed()) && hold == false) {
        motor.moveVelocity(0);
    }
} //please congratulate me for this one