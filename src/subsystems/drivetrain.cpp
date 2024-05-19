#include "subsystems/drivetrain.hpp"
using namespace okapi::literals;

okapi::Motor leftFront = okapi::Motor(-7); 
okapi::Motor leftMid = okapi::Motor(-6);
okapi::Motor leftBack = okapi::Motor(-5);
okapi::Motor rightFront = okapi::Motor(4);
okapi::Motor rightMid = okapi::Motor(2);
okapi::Motor rightBack = okapi::Motor(1);
//FROM THE BACK PERSPECTIVE

okapi::Controller controller = okapi::Controller();

okapi::ControllerButton r2 = okapi::ControllerButton(okapi::ControllerDigital::R2, false);

std::shared_ptr<okapi::OdomChassisController> drivetrain = okapi::ChassisControllerBuilder()
.withMotors({leftBack, leftMid, leftFront}, {rightBack, rightMid, rightFront})
.withDimensions(okapi::AbstractMotor::gearset::blue, {{1_in, 1_in}, okapi::imev5BlueTPR}) //TODO: find actual drive measurements
.withSensors(leftMid.getEncoder(), rightMid.getEncoder())
.withOdometry()
.buildOdometry();

void drive(bool &driveDisabled) {
    if(driveDisabled != true) {
        double speed = controller.getAnalog(okapi::ControllerAnalog::leftY); //left joystick
        double rotate = controller.getAnalog(okapi::ControllerAnalog::rightX); //right joystick
    
        drivetrain->getModel()->arcade(speed, rotate); //drive power
    }
}

void coastHold(bool &coast) {
    if(r2.changedToPressed()) {
        if(coast) { drivetrain->getModel()->setBrakeMode(okapi::AbstractMotor::brakeMode::hold); } 
        else { drivetrain->getModel()->setBrakeMode(okapi::AbstractMotor::brakeMode::coast); } 
    }
}