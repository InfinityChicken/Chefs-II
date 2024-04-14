#include "subsystems/drivetrain.hpp"    //no semicolon at end of #include statements

using namespace okapi::literals;

//do not write extern here, as you are constructing this variable in this file
//extern should only be used in header files (although there are some exceptions)
 
std::shared_ptr<okapi::ChassisController> drivetrain = 
okapi::ChassisControllerBuilder()
.withMotors({leftBack, leftMid, leftFront}, {rightBack, rightMid, rightFront})
.withDimensions(okapi::AbstractMotor::gearset::green, {{1_in, 1_in}, okapi::imev5GreenTPR}) //TODO: find actual drive measurements
// .withSensors(leftMid.getEncoder(), rightMid.getEncoder()); TODO: make this work bc we pass in motor integers but we need to pass in motor objects
.build();
