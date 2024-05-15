#include "subsystems/intake.hpp"

okapi::Motor intake = okapi::Motor(7);
okapi::ControllerButton l1 = okapi::ControllerButton(okapi::ControllerDigital::L1, false);
okapi::ControllerButton l2 = okapi::ControllerButton(okapi::ControllerDigital::L2, false);

void intakeStep() { //l1 holds for intake, l2 holds for outtake
    if ((!l1.isPressed() && !l2.isPressed()) || (l1.isPressed() && l2.isPressed())) { //if nothing is pressed or everything is pressed, the motor turns off
        intake.moveVelocity(0);
    } 
    
    else if (l1.isPressed()) { //if l1 is held and l2 isn't held the intake intakes
        intake.moveVelocity(600); //only runs on the tick at which l1 is pressed
 //also tells the first if statement that hold is disabled
    } 
    
    else if (l2.isPressed()) { //if l2 is held and l1 isn't the intake outakes
        intake.moveVelocity(-600); //only runs on the tick at which l2 is pressed
//also tells the first if statement that hold is disabled
    } 
}

//TODO: we have a blue cart right