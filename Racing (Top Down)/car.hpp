#pragma once

#include <vector>

const float maxSpeed = 10.0,
				acc = 0.2, 
				dec = 0.3,
				turnSpeed = 0.008,
				maxAngleInc = 0.1;

struct Car
{
	float x, y, 
	  	speed,
	  	angleInc,
	  	angle,
	  	direction,
	  	drift;
	int n;

	Car()	{
		speed = 2;
		angleInc = 0;
		n = 0;
		direction = 0;
		angle = 0;
	}

	void setSpeed(float spd) {
		speed = spd;
	}
	void setPos(float posx, float posy) {
		x = posx;
		y = posy;
	}

	void move();
	// void findTarget();
	void accellerate();
	void brake();
	void coast();
	void turnL();
	void turnR();
};