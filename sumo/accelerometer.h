#ifndef ACCELEROMETER_H_
#define ACCELEROMETER_H_

#define DIR_N 1
#define DIR_FRONT 1
#define DIR_E 2 // Right
#define DIR_S 3 // Back
#define DIR_W 4 // Left


class Accelerometer
{
public:

	/* Initialize the accelerometer */
	void setup();


	/* Called to read the next value */
	void update();



	/* Returns whether or not the robot just collided */
	int collided();

	/* Returns the direction of the collision */
	int getDirection();



};



#endif /* ACCELEROMETER_H_ */
