#include "auton/util.hpp"

okapi::IterativePosPIDController drivePID = okapi::IterativeControllerFactory::posPID(0, 0, 0);

okapi::IterativePosPIDController turnPID = okapi::IterativeControllerFactory::posPID(0, 0, 0);

void driveDistance (double distToTarget) {

    // if(abs(distToTarget) <=0.01) {return;} TODO: isn't this unnecessary?
    
    okapi::Rate rate;
    
    drivePID.setTarget(distToTarget); //set pid object target

    double originX = drivetrain->getState().x.convert(okapi::inch); //get origin point
    double originY = drivetrain->getState().y.convert(okapi::inch);

    double displacement = 0;

    while (abs(distToTarget-displacement) >= 0.083 || abs(leftFront.getActualVelocity()) > 8) { //TODO: why is this an or statement lmao. also check the distToTarget/displacement condition - 0.083=1inch
        double currX = drivetrain->getState().x.convert(okapi::inch);
        double currY = drivetrain->getState().y.convert(okapi::inch);

        double diffX = currX - originX;
        double diffY = currY - originY;

        displacement = sqrt(pow(diffX, 2) + pow(diffY, 2));

        // if (distToTarget < 0) {
        //     displacement = -displacement;
        // } TODO: what is this.

        double vel = drivePID.step(displacement * 36 / 60); //change to reflect gear ratios

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
        angle = fmod(-angle, 360) * -1 +360; //finds the explementary POSTIIVE angle, makes it 0<x<360, then makes it negative again to find the positive equivalent angle 
    }

    return (angle <= 180) ? angle : angle - 360; //fixes angle into range from 180 to -180. i think.
}

void turnDegrees (double targetAngle) {

    okapi::Rate rate;

    // double displacement = fixAngle(imu.controllerGet() - targetAngle); //TODO: why initialize originAngle here? is it bc you need to set the imu start pos 

    targetAngle = fixAngle(targetAngle);

    double originAngle = -targetAngle;

    imu.reset(originAngle); //sets origin for the imu to the negative of the target angle so that it targets 0

    turnPID.setTarget(0);

    double displacement; //very bad coding practice lmao
    
    while(abs(targetAngle-displacement) >= 3 || abs(leftFront.getActualVelocity()) > 15) { //TODO: value 15rpm (motor) here may have to be tuned, so may 3deg
        
        double currAngle = fixAngle(imu.controllerGet());

        displacement = fixAngle(currAngle-originAngle);

        double vel = turnPID.step(displacement); //TODO: gear ratios necessary here?

        drivetrain->getModel()->tank(0.9*vel, 0.9*-vel); //TODO: is the negatisation right 

        rate.delay(100_Hz);
        
    }

    turnPID.reset();
    imu.reset();

    drivetrain->getModel()->tank(0,0);
}
