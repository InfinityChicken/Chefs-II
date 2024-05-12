#include "include/auton/util.hpp"

void driveDistance (double distToTarget) {

    // if(abs(distToTarget) <=0.01) {return;} TODO: isn't this unnecessary?
    
    okapi::Rate rate;

    okapi::IterativePosPIDController drivePID = okapi::IterativeControllerFactory::posPID(0, 0, 0); //pid object
    
    drivePID.setTarget(distToTarget); //set pid object target

    double originX = drivetrain->getState().x.convert(okapi::foot); //get origin point
    double originY = drivetrain->getState().y.convert(okapi::foot);

    double displacement = 0; //set distance traveled object

    while (abs(distToTarget-displacement) >= 0.083 || abs(leftFront.getActualVelocity()) > 8) { //TODO: why is this an or statement lmao. also check the distToTarget/displacement condition - 0.083=1inch
        double currX = drivetrain->getState().x.convert(okapi::foot);
        double currY = drivetrain->getState().y.convert(okapi::foot);

        double diffX = currX - originX;
        double diffY = currY - originY;

        displacement = sqrt(pow(diffX, 2) + pow(diffY, 2));

        // if (distToTarget < 0) {
        //     displacement = -displacement;
        // } TODO: what is this.

        double vel = drivePID.step((displacement*36) / 60); //change to reflect gear ratios

        drivetrain -> getModel() -> tank(vel, vel);

        rate.delay(100_Hz);
    }

    drivePID.reset();

    drivetrain->getModel()->tank(0,0);
}

double fixAngle(double angle) { //TODO: i think this is a very roundabout way to solve this issue but i'm probably just chronically impaired
    if (angle == 0) {
        return 0;
    } else if (angle > 0) {
        angle = fmod(angle, 360); //makes the angle 0<x<360
    } else {
        angle = fmod(-angle, 360) * -1 +360; //finds the explementary NEGATIVE angle, makes it -360<x<0, then makes it negative again to find the positive equivalent angle 
    }

    return (angle <= 180) ? angle : angle - 360; //fixes angle into range from 180 to -180. i think. it's 12:30 i have one more day to finish i am cooked beyond belief

    // double decimal = angle - (int)angle;
    // int integer = (int)angle;

    // if (integer>0) {
    //     integer = integer % 360; //makes the angle less than 360
    // } else {
    //     integer = (-integer % 360) * -1 +360; //makes the angle positive and less than 360 then makes it negative again to find the positive equivalent angle 
    // }

    // angle = decimal + integer;
}

void turnDegrees (double targetAngle) {

    okapi::Rate rate;

    okapi::IterativePosPIDController turnPID = okapi::IterativeControllerFactory::posPID(0, 0, 0);

    double displacement = fixAngle(imu.controllerGet() - targetAngle); //TODO: why initialize originAngle here? is it bc you need to set the imu start pos 

    turnPID.setTarget(0);
    
    while(displacement >= 3 || abs(leftFront.getActualVelocity()) > 15) { //TODO: value 15rpm (motor) here may have to be tuned, so may 3deg
        displacement = fixAngle(imu.controllerGet() - targetAngle);

        // if (displacement >= 190) { //TODO: why does this exist
        //     break;
        // }

        double rpm = turnPID.step(displacement * 36 / 60); //TODO: gear ratios necessary here?

        drivetrain->getModel()->tank(-rpm, rpm); //TODO: is the negatisation right

        rate.delay(100_Hz);
    }
}