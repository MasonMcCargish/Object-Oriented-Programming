#pragma once

#include <vector>

const int num = 8; // checkpoints
const int points[num][2] = { 300,  610,  1270, 430,  1380, 2380, 1900, 2460,
                       1970, 1700, 2550, 1680, 2560, 3150, 500,  3300 };

const float maxSpeed = 8.0,
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
	  	direction;
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