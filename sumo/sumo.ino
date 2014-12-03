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
        while(1){
		//front_ir.update();
		//back_ir.update();
                left_ir.update();
               // right_ir.update();
          
                left_ir.objectAhead();
              //  Serial.print(front_ir.objectAhead());
                Serial.print(" ");
               // Serial.print(back_ir.objectAhead());
                Serial.print(" ");
                //Serial.print(left_ir.objectAhead());
                Serial.print(" ");
               // Serial.println(right_ir.objectAhead());
               
                delay(200);
        }
  
  
  
	waitForStart();
	robotMotor.arc(DIR_LEFT,35);

	while(1){

		// Update motors
		// Take sensor readings

		refl.update();
		front_ir.update();
		back_ir.update();
                left_ir.update();
                right_ir.update();

		// State actions
		switch(STATE){
			case STATE_START: 
				// Begin arching
				robotMotor.arc(DIR_RIGHT, 35);

				STATE = STATE_LOCATE;
			        break;
			case STATE_LOCATE:  // Eventually all other states should go back to this one once they are done

                                  
				// Check IR sensor for other robot

				if(front_ir.objectAhead()){ // Found straight ahead
					STATE = STATE_ATTACK;
                                  buzzer.playNote(NOTE_C(3), 200, 15);
				}
				else if(back_ir.objectAhead()){ // Found behind
					// Modify motot arching
					robotMotor.arc(DIR_RIGHT, 0);
                                  //buzzer.playNote(NOTE_G(3), 200, 15);
				}
                                else if(right_ir.objectAhead()){ // Found behind
					// Modify motot arching
					robotMotor.arc(DIR_LEFT, 0);
                                 // buzzer.playNote(NOTE_F(3), 200, 15);
				}
                               /* else if(left_ir.objectAhead()){ // Found behind
					// Modify motot arching
					robotMotor.arc(DIR_LEFT, 5);
				}*/
			        break;
			case STATE_ATTACK: 
				// Track robot and move towards it
				if(!front_ir.objectAhead()){
					STATE = STATE_START;
				}
				else
					robotMotor.forward();
			        break;
			case STATE_ENGAGE: 
				// Go straight on full power
				robotMotor.forward();
			        break;
			case STATE_DEFEND: 

				// Depending on the collision angle, try to evade

			        break;
			case STATE_EDGE: 
				// Depending on which reflectance sensor was hit, turn to not fall off
                                  
				if(refl.onEdge() == DIR_RIGHT){
                                        robotMotor.backward();
                                        delay(500);
					robotMotor.arc(DIR_LEFT, 0);
				}
				else if(refl.onEdge() == DIR_LEFT){
                                        robotMotor.backward();
                                        delay(500);
					robotMotor.arc(DIR_RIGHT, 0);
				}
				else{
					delay(300);
					STATE = STATE_START;
				}

			      break;
		}


		// Special case state transitions

		if(refl.onEdge() == DIR_RIGHT || refl.onEdge() == DIR_LEFT){ // Edge detected
			STATE = STATE_EDGE;
                        
		}



		// Sleep
		delay(33);
	}

}
