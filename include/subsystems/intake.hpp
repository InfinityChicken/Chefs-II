#ifndef INTAKE
#define INTAKE

#include "main.h"

extern okapi::Motor intake;
extern okapi::ControllerButton l1;

void intakeStep(okapi::Motor motor, int &intakeState);

#endif