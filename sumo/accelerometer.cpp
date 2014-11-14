#include "accelerometer.h"
#include <Arduino.h>
#include <Wire.h>
#include <LSM303.h>

/* Insert code for accelerometer */
/* It should detect a collision and determine the angle of collision */
#define SENSITIVITY  4

LSM303 compass;

int lastValuesX[SENSITIVITY];
int lastValuesY[SENSITIVITY];

int index;

int averageArray(int values[])
{
    int averaged = 0;
     for(int i = 0; i < sizeof(values); i=i+1)
     {
       if(values[i]!=0)
       {
         averaged = averaged + values[i];
       }
     }
     averaged = averaged/sizeof(values);
     return averaged;
}


void Accelerometer::setup(){
	compass.init();
	compass.enableDefault();
       Wire.begin();
        index =0;
}


void Accelerometer::update(){
  /*
  
  return atan2(last.x, last.y) * 180.0 / M_PI;
  
  */
     compass.read();
    
     lastValuesX[index] = compass.a.x;
     lastValuesY[index] = compass.a.y;
     
     int averagedX = averageArray(lastValuesX);
     
     int averagedY = averageArray(lastValuesY);
     
      index = index+1;
      index = index % SENSITIVITY;
	
      int averageXY = sqrt(averagedX*averagedX + averagedY*averagedY);
      Serial.println(averageXY);
	//this is where stuff will go
}





int Accelerometer::collided(){
  
  return 0;

}


int Accelerometer::getDirection(){
  
  return 0;
}
