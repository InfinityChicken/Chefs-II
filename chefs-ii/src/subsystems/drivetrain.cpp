#include "subsystems/drivetrain.hpp";
using namespace okapi::literals;

extern std::shared_ptr<okapi::ChassisController> drivetrain = 
okapi::ChassisControllerBuilder()
.withMotors({leftBack, leftMid, leftFront}, {rightBack, rightMid, rightFront})
.withDimensions(okapi::AbstractMotor::gearset::green, {{1_in, 1_in}, okapi::imev5GreenTPR}) //TODO: find actual drive measurements
.build();