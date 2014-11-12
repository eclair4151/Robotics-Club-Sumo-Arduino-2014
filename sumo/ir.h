#ifndef IR_H_
#define IR_H_


class IrSensor
{
public:
	IrSensor(int pin);

	/* Reads the sensor */
	void update();

	/* Get the current distance in cm */
	int distance();

	float voltage();

	/* Returns true if there is an object somewhere in front of the sensor */
	int objectAhead();

private:
	int pin;
	int lastVal;
	int val;
};



#endif
