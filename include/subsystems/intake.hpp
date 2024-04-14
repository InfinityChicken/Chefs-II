#ifndef INTAKE_HPP
#define INTAKE_HPP

#include "main.h"

okapi::Motor intake(7);
okapi::ControllerButton l1 = okapi::ControllerButton(okapi::ControllerDigital::L1, false); //I FIGURED OUT HOW TO USE THE :: THING I DESERVE A STANDING OVATION
int intakeState;

void intakeStep(okapi::Motor motor, int &intakeState);

#endif