#include "main.h"
#include "subsystems/drivetrain.hpp"
#include "subsystems/intake.hpp"
#include "subsystems/slapper.hpp"
#include "subsystems/messaging.hpp"
#include "auton/util.hpp"
#include "auton/paths.hpp"

using namespace okapi::literals;

/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(1, "Hello PROS User!");

	pros::lcd::register_btn1_cb(on_center_button);
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {

}

void opcontrol() {
	// okapi::ControllerButton x = okapi::ControllerButton(okapi::ControllerDigital::X); //TODO: TESTING OBJECTS REMOVE LATER!!!
	// okapi::ControllerButton y = okapi::ControllerButton(okapi::ControllerDigital::Y); //TODO: TESTING OBJECTS REMOVE LATER!!!
	okapi::Rate rate;
	int slapperState = 0;
	bool driveDisabled = false;
	bool coast = true;

	drivetrain->getModel()->setBrakeMode(okapi::AbstractMotor::brakeMode::coast);

	while(true) {
		coastHold(coast);

		drive(driveDisabled);

		intakeStep();

		slapperStep(slapperState, driveDisabled);

		// overheat(motors, controller, x);

		rate.delay(100_Hz);

		// if(x.changedToPressed()) {
		// 	driveDistance(12);
		// }

		// if(y.changedToPressed()) {
		// 	turnDegrees(90);
		// }
	}
}

// public static void main(String[] args) {
// 	System.out.println("Will the chef cook or will he be cooked?");
// }