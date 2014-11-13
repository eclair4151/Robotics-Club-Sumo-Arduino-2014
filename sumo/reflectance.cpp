#include "reflectance.h"

/* Code to detect white edge line */

#include <QTRSensors.h>
#include <ZumoReflectanceSensorArray.h>


#define QTR_THRESHOLD  1500

#define NUM_SENSORS 6
unsigned int sensor_values[NUM_SENSORS];

ZumoReflectanceSensorArray sensors(QTR_NO_EMITTER_PIN);


void Reflectance::update(){
	sensors.read(sensor_values);
}


int Reflectance::onEdge(){
	if(sensor_values[0] < QTR_THRESHOLD)
		return 1;

	if(sensor_values[5] < QTR_THRESHOLD)
		return 2;


	return 0;
}
