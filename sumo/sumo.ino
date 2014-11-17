#include "sumo.h"
#include <Wire.h>
#include <LSM303.h>
#include <QTRSensors.h>
#include <ZumoMotors.h>
#include <ZumoReflectanceSensorArray.h>
#include <ZumoBuzzer.h>
#include <Pushbutton.h>
#include <Arduino.h>


static int STATE = STATE_START;

void setup()
{
	Serial.begin(9600);

	accel.setup();

}


ZumoBuzzer buzzer;
Pushbutton button(ZUMO_BUTTON);

void waitForStart()
{
	button.waitForButton();

	for (int i = 0; i < 5; i++)
	{
		delay(1000);
		buzzer.playNote(NOTE_G(3), 200, 15);
	}
}


void loop()
{

	//waitForStart();
	robotMotor.arc(DIR_RIGHT,35);

	while(1){

		// Update motors
		// Take sensor readings
		//accel.update();
		refl.update();
		front_ir.update();
		back_ir.update();

		if(refl.onEdge())
		{
			Serial.println("HIT LINE");
		}

		// State actions
		switch(STATE){
			case STATE_START: {
				// Begin arching
				robotMotor.arc(DIR_RIGHT, 35);

				STATE = STATE_LOCATE;
			}
			case STATE_LOCATE: { // Eventually all other states should go back to this one once they are done


				// Check IR sensor for other robot

				if(front_ir.objectAhead()){ // Found straight ahead
					STATE = STATE_ATTACK;
				}
				else if(back_ir.objectAhead()){ // Found behind
					// Modify motot arching
					robotMotor.arc(DIR_LEFT, 5)
				}

			}
			case STATE_ATTACK: {
				// Track robot and move towards it
				if(!front_ir.objectAhead()){
					STATE = STATE_START;
				}
				else
					robotMotor.forward();
			}
			case STATE_ENGAGE: {
				// Go straight on full power
				robotMotor.forward();
			}
			case STATE_DEFEND: {

				// Depending on the collision angle, try to evade

			}
			case STATE_EDGE: {
				// Depending on which reflectance sensor was hit, turn to not fall off

				if(refl.onEdge() == DIR_RIGHT){
					robotMotor.arch(DIR_LEFT, 0);
				}
				else if(refl.onEdge() == DIR_LEFT){
					robotMotor.arch(DIR_RIGHT, 0);
				}
				else{
					delay(100);
					STATE = STATE_STARt;
				}

			}
		}


		// Special case state transitions

		if(refl.onEdge()){ // Edge detected
			STATE = STATE_EDGE;
		}

		if(accel.collided()){ // Collision

			if(accel.getDirection() == DIR_FRONT){ // Head-on
				STATE = STATE_ENGAGE;
			}
			else{
				STATE = STATE_DEFEND;
			}
		}


		// Sleep
		delay(33);
	}

}
