#include "main.h";

//ports are arbitrary, just make sure that the signs stay the same
extern const int8_t leftFront = 1;
extern const int8_t leftMid = 2;
extern const int8_t leftBack = 3;
extern const int8_t rightFront = -4;
extern const int8_t rightMid = -5;
extern const int8_t rightBack = -6;

extern std::shared_ptr<okapi::ChassisController> drivetrain;