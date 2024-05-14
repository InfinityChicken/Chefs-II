#ifndef SLAPPER
#define SLAPPER

#include "main.h"
#include "drivetrain.hpp"

extern okapi::Motor slapper;
extern okapi::ControllerButton r1;

void slapperStep(int &slapperState, bool &driveDisabled);

#endif