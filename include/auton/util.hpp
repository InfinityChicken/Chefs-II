#ifndef UTIL
#define UTIL

#include "main.h"
#include "subsystems/drivetrain.hpp"
#include "subsystems/sensors.hpp"
#include <cmath>
using namespace okapi::literals;

extern okapi::IterativePosPIDController drivePID;

extern okapi::IterativePosPIDController turnPID;

void driveDistance (double distToTarget);

double fixAngle(double angle);

void turnDegrees (double targetAngle);

#endif