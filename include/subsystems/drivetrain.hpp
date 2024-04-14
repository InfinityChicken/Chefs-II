#include "main.h"

//ports are arbitrary, just make sure that the signs stay the same
extern okapi::Motor leftFront;
extern okapi::Motor leftMid;
extern okapi::Motor leftBack;
extern okapi::Motor rightFront;
extern okapi::Motor rightMid;
extern okapi::Motor rightBack;

// extern okapi::Motor leftFront(1);
// extern okapi::Motor leftMid(2);
// extern okapi::Motor leftBack(3);
// extern okapi::Motor rightFront(-4);
// extern okapi::Motor rightMid(-5);
// extern okapi::Motor rightBack(-6);

extern std::shared_ptr<okapi::ChassisController> drivetrain;

void drive(okapi::Controller controller, std::shared_ptr<okapi::ChassisController> drivetrain);