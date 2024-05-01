#ifndef SLAPPER
#define SLAPPER

#include "main.h"

extern okapi::Motor slapper;
extern okapi::ControllerButton r1;

void slapperStep(okapi::Motor &motor, int &slapperState, okapi::ControllerButton &r1, bool &driveDisabled, okapi::Controller &controller);

#endif