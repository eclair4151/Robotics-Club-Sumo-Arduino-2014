#include "reflectance.h"

#include <QTRSensors.h>
#include <ZumoReflectanceSensorArray.h>

ZumoReflectanceSensorArray sensors;
#define NUM_SENSORS 6
unsigned int sensor_values[NUM_SENSORS];


/* Insert code to detect white edge line */

int Reflectance::onEdge(){
  
  sensors.read(sensor_values);
  
  int left = sensor_values[0];
  int right = sensor_values[5];
  return (right < 250 || left < 250);

}

