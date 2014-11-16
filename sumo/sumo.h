#ifndef SUMO_H_
#define SUMO_H_

#include "ir.h"
#include "accelerometer.h"
#include "motor.h"
#include "reflectance.h"

#define TESTING 1

#define STATE_START  0 // STATE = 0: Start state, nothing happening
#define STATE_LOCATE 1 // STATE = 1: Locating Mode - Arching until we see the other robot
#define STATE_ATTACK 2 // STATE = 2: Attack Mode - Follow the detected robot
#define STATE_ENGAGE 3 // STATE = 3: Engagement Mode - entered when hitting a robot straight on; go forward at full power
#define STATE_DEFEND 4 // STATE = 4: Defense Mode - Based on the enemies attack vector, manuever to safety
#define STATE_EDGE   5 // STATE = 5: Edge Case - Don't fall off the edge


IrSensor front_ir(0);
IrSensor back_ir(1);

Reflectance refl;
Accelerometer accel;
Motor robotMotor;

#endif /* SUMO_H_ */



