#include "accelerometer.h"
#include <Arduino.h>
#include <Wire.h>
#include <LSM303.h>

/* Insert code for accelerometer */
/* It should detect a collision and determine the angle of collision */
#define SENSITIVITY  2
#define ACCELEROMETER_THRESHOLD 1000


LSM303 compass;

int lastValuesX[SENSITIVITY];
int lastValuesY[SENSITIVITY];
int lastValuesZ[SENSITIVITY];
int index;

int averageArray(int values[])
{
	int averaged = 0;
	int numbers = 0;
	for(int i = 0; i < sizeof(values); i=i+1)
	{
		if(values[i]!=0)
		{
			averaged = averaged + values[i];
			numbers = numbers + 1;
		}
	}
	averaged = averaged/numbers;
	return averaged;
}


void Accelerometer::setup(){
	Wire.begin();
	compass.init();
	compass.enableDefault();

	memset(lastValuesX,0,sizeof(lastValuesX));
	memset(lastValuesY,0,sizeof(lastValuesY));
	memset(lastValuesZ,0,sizeof(lastValuesZ));
	index =0;

}


void Accelerometer::update(){
	/*
  return
  */
	compass.read();

	lastValuesX[index] = compass.a.x;
	lastValuesY[index] = compass.a.y;
	lastValuesZ[index] = compass.a.z;

	long averagedX = averageArray(lastValuesX);
	long averagedY = averageArray(lastValuesY);
	long averagedZ = averageArray(lastValuesZ);

	index = index+1;
	index = index % SENSITIVITY;

	long averageXY = sqrt(averagedX*averagedX + averagedY*averagedY);
	/*Serial.print(averagedX);
       Serial.print("      ");
       Serial.print(averagedY);
       Serial.print("      ");
       Serial.print(averageXY);
       Serial.print("      ");*/
	//int degree = atan2(averagedX, averagedY) * 180.0 / M_PI;
	//Serial.println(degree);

	if(averageXY > 3000)
	{
		Serial.println("HIT!");
	}
}





int Accelerometer::collided(){

	return 0;

}


int Accelerometer::getDirection(){

	return 0;
}
