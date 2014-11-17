/* Insert code to perform parametrized arching */
#include "motor.h"
#include <ZumoMotors.h>

ZumoMotors motor;

void Motor::arc(int dir, float r)
{
	float v1 , v2;
	float r1 = r - ROBOT_HALF;
	float r2 = r + ROBOT_HALF;

	if(dir == DIR_LEFT)
	{
		v1 = MOTOR_POWER;
		v2 = (v1*r2)/r1;


	}
	else if(dir == DIR_RIGHT)
	{

		v2 = MOTOR_POWER;
		v1 = (v2*r1)/r2;
	}
	motor.flipRightMotor(true);
	motor.setSpeeds(v1,v2);

	Serial.print(v1);
	Serial.print("    ");
	Serial.println(v2);
}

void Motor::forward()
{
	motor.flipRightMotor(true);
	motor.setSpeeds(MOTOR_POWER, MOTOR_POWER);
}

void Motor::stop()
{
	motor.setSpeeds(0, 0);
}
