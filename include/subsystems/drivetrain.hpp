#include "main.h"

//ports are arbitrary, just make sure that the signs stay the same
okapi::Motor leftFront;
okapi::Motor leftMid;
okapi::Motor leftBack;
okapi::Motor rightFront;
okapi::Motor rightMid;
okapi::Motor rightBack;

extern std::shared_ptr<okapi::ChassisController> drivetrain;