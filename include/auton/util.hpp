#include "main.h"
#include "subsystems/drivetrain.hpp"
#include <cmath>

void driveDistance (double distToTarget) {
    if(abs(distToTarget) <=0.01) {return;}
    
    okapi::IterativePosPIDController drivePID = okapi::IterativeControllerFactory::posPID(0, 0, 0); //pid object
    
    drivePID.setTarget(distToTarget); //set pid object target

    double originX = drivetrain->getState().x.convert(okapi::foot); //get origin point
    double originY = drivetrain->getState().y.convert(okapi::foot);

    double displacement = 0; //set distance traveled object

    while (abs(distToTarget-displacement >= 1 || abs(leftFront.getActualVelocity())) > 8) {
        double currX = drivetrain->getState.x().convert(okapi::foot);
        double currY = drivetrain->getState.y().convert(okapi::foot);

        double diffX = currX - originX;
        double diffY = currY - originY;

        displacement = Math.sqrt(Math.pow(diffX, 2) + Math.pow(diffY, 2));

        if (target < 0) {
            displacement = -displacement;
        }

        double vel = drivePID.step((displacement*36) / 60); //change to reflect gear ratios

        drivetrain -> getModel() -> tank(vel, vel);
    }

    drivePID.reset();

    drivetrain->getModel()->tank(0,0);
}


// double fixAngle(double d) {
//     if (theta==0) {
//         return;
//     }

//     double fp = d-(int)d;
//     int id = (int)d;

//     if (d>0) {
        
//     }
//         id = id%360
//     }

//     if (d > 0) {
//        id = id % 360;
//     }
// }