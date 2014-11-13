#include "reflectance.h"

/* Code to detect white edge line */

#include <QTRSensors.h>
#include <ZumoReflectanceSensorArray.h>


#define QTR_THRESHOLD  250

#define NUM_SENSORS 6
unsigned int sensor_values[NUM_SENSORS];

ZumoReflectanceSensorArray sensors(QTR_NO_EMITTER_PIN);


void Reflectance::update(){
	sensors.read(sensor_values);
}


int Reflectance::onEdge(){

	int left = sensor_values[0];
	int right = sensor_values[5];
	return (right < QTR_THRESHOLD || left < QTR_THRESHOLD);

}
