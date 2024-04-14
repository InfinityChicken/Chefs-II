#include "main.h"       //no semicolon should be here

//ports are arbitrary, just make sure that the signs stay the same

const int8_t leftFront = 0;     //don't assign any values to an extern statement
const int8_t leftMid = 0;      
const int8_t leftBack = 0;      //(technically you should *define* and assign any variable in a src file, it's better
const int8_t rightFront = 0;    //origanization and the compiler won't be forced to recompile every single file that
const int8_t rightMid = 0;      //this header is linked to.) 
const int8_t rightBack = 0;     //(it's better to use constexpr or define in this case but don't worry about that rn.)

//About the LOG_INFO stuff, just ignore it. The compiler is saying that there is a small risk of 
//the program crashing if you capture class pointer lambda function arguments using copy, but that's 
//only if we using multithreading and we are not doing that right now

extern std::shared_ptr<okapi::ChassisController> drivetrain;    //good
