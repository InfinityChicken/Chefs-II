#ifndef INTAKE
#define INTAKE

#include "main.h"

extern okapi::Motor intake;
extern okapi::ControllerButton l1; //intake button
extern okapi::ControllerButton l2; //outtake button

void intakeStep(); //intake tick function

#endif