#include "subsystems/intake.hpp"

okapi::Motor intake = okapi::Motor(7);
okapi::ControllerButton l1 = okapi::ControllerButton(okapi::ControllerDigital::L1, false);
okapi::ControllerButton l2 = okapi::ControllerButton(okapi::ControllerDigital::L2, false);

void intakeStep() { //goal: l1 holds for intake, l2 holds for outtake, l1+l2 toggle intake
}

/*
example scenario: 
l1 is pressed down, so the second if statement runs for one tick and the motor intakes. 
l2 is then pressed down, so the third if statement runs for one tick and the motor toggles to hold.
l1 is released and nothing runs --- nothing was changed to pressed in the last tick.
l2 is released and nothing runs --- nothing was changed to pressed in the last tick.
l2 is pressed down, so the second if statement runs for one tick and the motor outtakes and turns off hold.
l2 is released and the first if statement runs, turning off the intake.
the first if statement continues to run until another intake button is pressed.
*/