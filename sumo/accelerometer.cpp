#include "accelerometer.h"
#include <Arduino.h>
#include <Wire.h>
#include <LSM303.h>

/* Insert code for accelerometer */
/* It should detect a collision and determine the angle of collision */

LSM303 compass;


void Accelerometer::setup(){
	compass.init();
	compass.enableDefault();
}

void Accelerometer::update(){
	compass.read();
	//this is where stuff will go
}


int Accelerometer::collided(){
  return 0;

}


int Accelerometer::getDirection(){
  return 0;
}
