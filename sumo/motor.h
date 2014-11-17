#ifndef MOTOR_H_
#define MOTOR_H_



#define DIR_RIGHT 1
#define DIR_LEFT 2
#define MOTOR_POWER 400
#define ROBOT_HALF 4.65

class Motor
{
public:
	/* Begin moving in an arc determined by the given direction and radius of the circle (in cm) */
	void arc(int dir, float r);

	void forward();

	void stop();

};

#endif /* MOTOR_H_ */
