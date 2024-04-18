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

extern okapi::ControllerButton r2;

extern std::shared_ptr<okapi::ChassisController> drivetrain;

void drive(okapi::Controller controller, std::shared_ptr<okapi::ChassisController> drivetrain);

void coastHold(std::shared_ptr<okapi::ChassisController> drivetrain);

#endif