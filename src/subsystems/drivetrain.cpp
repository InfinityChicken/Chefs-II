#include "subsystems/drivetrain.hpp"
using namespace okapi::literals;

okapi::Motor leftFront = okapi::Motor(1);
okapi::Motor leftMid = okapi::Motor(2);
okapi::Motor leftBack = okapi::Motor(3);
okapi::Motor rightFront = okapi::Motor(-4);
okapi::Motor rightMid = okapi::Motor(-5);
okapi::Motor rightBack = okapi::Motor(-6);

std::shared_ptr<okapi::ChassisController> drivetrain = 
okapi::ChassisControllerBuilder()
.withMotors({leftBack, leftMid, leftFront}, {rightBack, rightMid, rightFront})
.withDimensions(okapi::AbstractMotor::gearset::blue, {{1_in, 1_in}, okapi::imev5BlueTPR}) //TODO: find actual drive measurements
.withSensors(leftMid.getEncoder(), rightMid.getEncoder())
.build();

void drive(okapi::Controller controller, std::shared_ptr<okapi::ChassisController> drivetrain) {
    double speed = controller.getAnalog(okapi::ControllerAnalog::leftY); //left joystick
    double rotate = controller.getAnalog(okapi::ControllerAnalog::rightX); //right joystick
    
    drivetrain->getModel()->arcade(speed, rotate); //drive power
}