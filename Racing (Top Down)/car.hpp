#pragma once

#include <vector>
#include "score.hpp"

#include <SFML/Graphics.hpp>
using namespace sf;

const float maxSpeed = 10.0,
				acc = 0.2, 
				dec = 0.1,
				turnSpeed = 0.008,
				maxAngleInc = 0.05;

struct Car
{
	float x, y, 
	  	speed,
	  	angleInc,
	  	angle,
	  	direction,
	  	drift;
	int n;
	Score s;

	Texture t;
	Sprite sCar;

	Car()	{
		speed = 0;
		angleInc = 0;
		n = 0;
		direction = 0;
		angle = 0;

		t.loadFromFile("images/car.png");
   	t.setSmooth(true);
   	sCar.setTexture(t);
   	sCar.setOrigin(22, 22);
	}

	void setSpeed(float spd) {
		speed = spd;
	}
	void setPos(float posx, float posy) {
		x = posx;
		y = posy;
	}

	void driftChange(float);
	void move();
	void accellerate();
	void brake();
	void coast();
	void turnL();
	void turnR();
	Sprite mvSprite(int, int);
};