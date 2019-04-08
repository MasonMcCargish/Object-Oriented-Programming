#include "car.hpp"

#include <cmath>
#include <algorithm>
#include <random>

void Car::move()
{

	if(speed > .1) {
		angle += angleInc;
		direction += (drift) / 50;
	}
	else {
		drift = 0;
		angleInc = 0;
		direction = angle;
	}
	drift = angle - direction;

	if(speed > 0)
		speed -= abs(drift) * .2;

	x += std::sin(direction) * speed;
	y -= std::cos(direction) * speed;
}

// void Car::findTarget()
// {
// 	 float tx = points[n][0];
// 	 float ty = points[n][1];
// 	 float beta = angle - std::atan2(tx - x, -ty + y);
// 	 if (std::sin(beta) < 0)
// 	   angle += 0.005 * speed;
// 	 else
// 	   angle -= 0.005 * speed;
// 	 if ((x - tx) * (x - tx) + (y - ty) * (y - ty) < 25 * 25)
// 	   n = (n + 1) % num;
// }

void Car::accellerate()
{
	if(speed < maxSpeed) {
		if (speed < 0)
         speed += dec;
      else
         speed += acc;
	}
}

void Car::brake()
{
	if(speed > -maxSpeed) {
		if (speed > 0)
         speed -= dec;
      else
         speed -= acc;
	}
}

void Car::coast()
{
	if (speed - dec > 0)
      speed -= dec;
   else if (speed + dec < 0)
      speed += dec;
   else
      speed = 0;
}

void Car::turnL()
{
	if (speed != 0 && angleInc > -maxAngleInc) {
   	angleInc -= turnSpeed * speed / maxSpeed;
   }

}

void Car::turnR()
{
	if (speed != 0 && angleInc < maxAngleInc) {
      angleInc += turnSpeed * speed / maxSpeed;
	}
}