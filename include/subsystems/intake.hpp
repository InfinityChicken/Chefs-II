#ifndef INTAKE
#define INTAKE

#include "main.h"

extern okapi::Motor intake;
extern okapi::ControllerButton l1;
extern okapi::ControllerButton l2;

void intakeStep(okapi::Motor motor, okapi::ControllerButton l1, okapi::ControllerButton l2, bool &hold);

#endif