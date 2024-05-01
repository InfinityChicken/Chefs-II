#ifndef MESSAGING
#define MESSAGING

#include "main.h"
#include<array>
#include<string>
using namespace std;

extern okapi::ControllerButton x;

void overheat(okapi::Motor motors[8], okapi::Controller &controller, okapi::ControllerButton &x);

#endif