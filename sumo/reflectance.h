#ifndef RELFECTANCE_H_
#define RELFECTANCE_H_

#define DIR_RIGHT 1
#define DIR_LEFT 2
#define QTR_THRESHOLD  250
#define NUM_SENSORS 6

class Reflectance
{
public:

	/* Read the reflectance array */
	void update();

	int onEdge();


};


#endif /* RELFECTANCE_H_ */



