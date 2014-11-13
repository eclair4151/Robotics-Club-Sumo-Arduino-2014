#include "sumo.h"
#include <QTRSensors.h>
#include <ZumoReflectanceSensorArray.h>


#include <Arduino.h>

static int STATE = STATE_START;

void setup()
{
	Serial.begin(9600);
}

void loop()
{
	// Insert start button code here


	while(1){

		// Update motors

		// Take sensor readings



		// State actions
		switch(STATE){
			case STATE_START: {
				// Begin arching

				STATE = STATE_LOCATE;
			}
			case STATE_LOCATE: { // Eventually all other states should go back to this one once they are done
				// Check IR sensor for other robot

				if(front_ir.objectAhead()){ // Found straight ahead
					STATE = STATE_ATTACK;
				}
				else if(back_ir.objectAhead()){ // Found behind
					// Modify motot arching
				}

			}
			case STATE_ATTACK: {

				// Track robot and move towards it

			}
			case STATE_ENGAGE: {

				// Go straight on full power

			}
			case STATE_DEFEND: {

				// Depending on the collision angle, try to evade

			}
			case STATE_EDGE: {
                                 
				// Depending on which reflectance sensor was hit, turn to not fall off

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



