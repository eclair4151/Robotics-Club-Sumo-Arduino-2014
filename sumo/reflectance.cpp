#include "reflectance.h"

/* Code to detect white edge line */

#include <QTRSensors.h>
#include <ZumoReflectanceSensorArray.h>




unsigned int sensor_values[NUM_SENSORS];

ZumoReflectanceSensorArray sensors(QTR_NO_EMITTER_PIN);


void Reflectance::update(){
	sensors.read(sensor_values);
}


int Reflectance::onEdge(){

	int left = sensor_values[0];
	int right = sensor_values[5];

        if(right < QTR_THRESHOLD)
        {
          return DIR_RIGHT;
        }
        if(left< QTR_THRESHOLD)
        {
          return DIR_LEFT;
        }
        
        return 0;
}
