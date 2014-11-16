#include "ir.h"

#include <Arduino.h>

IrSensor::IrSensor(int pin){
	this->pin = pin;
	this->lastVal = 0;
	this->val = 0;
}


void IrSensor::update(){
	int v;

	this->lastVal = this->val;

	v = analogRead(this->pin);

	this->val = (this->lastVal * 0.2) + (v * 0.8);
}

int IrSensor::distance(){
	return (6762/(this->val-9))-4;
}

float IrSensor::voltage(){
	return (5.0/1024)*this->val;
}


int IrSensor::objectAhead(){
	return this->distance() > 0 && this->distance() < 250;
}
