#ifndef PATHS
#define PATHS

#include "main.h"
#include "util.hpp"
#include "subsystems/intake.hpp"
using namespace okapi::literals;

void farSimple() {
    driveDistance(72); //move in front of the middle of the goal
    turnDegrees(90);
    driveDistance(12); //score preload
    turnDegrees(180);
    driveDistance(15); //intake iso triball
    turnDegrees(180);
    driveDistance(15); //score iso triball
}

void farComplex() {
    okapi::Rate rate;
    driveDistance(48); //nav to the same line as the otu triball

    intake.moveVelocity(-600); //outtake
    rate.delayUntil(1_s);
    intake.moveVelocity(0);

    turnDegrees(90); //nav to otu triball
    driveDistance(36);

    intake.moveVelocity(600); //intake otu triball
    rate.delayUntil(1_s);
    intake.moveVelocity(0);

    turnDegrees(75.964); //score otu and preload triballs
    driveDistance(49.476);

    //TODO: finish
}

//aot reference???
//i'm not funny

#endif