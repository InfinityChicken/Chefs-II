#ifndef DRIVETRAIN
#define DRIVETRAIN

#include "main.h"

//ports are arbitrary, just make sure that the signs stay the same
extern okapi::Motor leftFront; 
extern okapi::Motor leftMid;
extern okapi::Motor leftBack;
extern okapi::Motor rightFront;
extern okapi::Motor rightMid;
extern okapi::Motor rightBack;

extern okapi::Controller controller;

extern okapi::ControllerButton r2;

// extern okapi::ControllerButton r2;
//TODO: coast hold toggle; r2 and coastHold will be used for that
extern std::shared_ptr<okapi::OdomChassisController> drivetrain;

void drive(bool &driveDisabled);

void coastHold(bool &coast);

#endif