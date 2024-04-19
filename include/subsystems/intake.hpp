#ifndef INTAKE
#define INTAKE

#include "main.h"

extern okapi::Motor intake;
extern okapi::ControllerButton l1; //intake button
extern okapi::ControllerButton l2; //outtake button

void intakeStep(okapi::Motor motor, okapi::ControllerButton l1, okapi::ControllerButton l2, bool &hold); //intake tick function

#endif