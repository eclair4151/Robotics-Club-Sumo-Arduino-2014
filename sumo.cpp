#include "sumo.h"

void setup()
{
	Serial.begin(9600);
}



static int STATE = STATE_START;

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

				if(){ // Found straight ahead
					STATE = STATE_ATTACK;
				}
				else{ // Found behind
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

		if(){ // Edge detected
			STATE = STATE_EDGE;
		}

		if(){ // Collision

			if(){ // Head-on
				STATE = STATE_ENGAGING;
			}
			else{
				STATE = STATE_DEFENDING;
			}


		}


		// Sleep
		delay(33);
	}

}





