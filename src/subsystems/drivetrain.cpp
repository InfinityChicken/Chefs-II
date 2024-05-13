#include "subsystems/drivetrain.hpp"
using namespace okapi::literals;

okapi::Motor leftFront = okapi::Motor(1); //TODO: motor groups, gear ratios, extra motor groups?
okapi::Motor leftMid = okapi::Motor(2);
okapi::Motor leftBack = okapi::Motor(3);
okapi::Motor rightFront = okapi::Motor(-4);
okapi::Motor rightMid = okapi::Motor(-5);
okapi::Motor rightBack = okapi::Motor(-6);

okapi::Controller controller = okapi::Controller();

// okapi::ControllerButton r2 = okapi::ControllerButton(okapi::ControllerDigital::R2, false);

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

// void coastHold(std::shared_ptr<okapi::ChassisController> drivetrain) { TODO: find out the difference between coast, hold, and brake and figure out how to do that using a drivetrain (ask does)
//     drivetrain->
// }