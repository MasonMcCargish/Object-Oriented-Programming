#include "car.hpp"

#include <cmath>
#include <algorithm>
#include <random>

void Car::move() {

	if(speed > .1) {
		angle += (angleInc);
		direction += (drift) / 50;
	}
	else {
		drift = 0;
		angleInc = 0;
		direction = angle;
	}
	drift = angle - direction;

	s.add(static_cast<int>(abs(drift * 10 * speed)));
	s.print();

	if(speed > 0)
		speed -= abs(drift) * .2;

	x += std::sin(direction) * speed;
	y -= std::cos(direction) * speed;
}

void Car::accellerate() {
	driftChange(.001);

	if(speed < maxSpeed) {
		if (speed < 0)
         speed += dec;
      else
         speed += acc;
	}
}

void Car::brake() {
	if(speed > -maxSpeed) {
		if (speed > 0)
         speed -= dec;
      else
         speed -= acc;
	}
}

void Car::coast() {
	driftChange(0);

	if (speed - dec > 0)
      speed -= dec;
   else if (speed + dec < 0)
      speed += dec;
   else
      speed = 0;
}

void Car::turnL() {
	if (speed != 0 && angleInc > -maxAngleInc) {
   	angleInc -= turnSpeed * speed / maxSpeed;
   }
}

void Car::turnR() {
	if (speed != 0 && angleInc < maxAngleInc) {
      angleInc += turnSpeed * speed / maxSpeed;
	}
}

void Car::driftChange(float c) {
	if(angle <= direction + 1 && angle > direction && speed > 3)
		angleInc -= (.002 + c);
	else if(angle >= direction - 1 && angle < direction && speed > 3)
		angleInc += (.002 - c);
}

Sprite Car::mvSprite(int offsX, int offsY) {
	sCar.setPosition(x - offsX, y - offsY);
   sCar.setRotation(angle * 180 / 3.141593);
   sCar.setColor(Color::Red);

   return sCar;
}