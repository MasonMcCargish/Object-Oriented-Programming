#include "bg.hpp"

Sprite BG::pan(int carX, int carY) {
	if (carX > 320)
      offsetX = carX - 320;
   if (carY > 240)
      offsetY = carY - 240;

   sBG.setPosition(-offsetX, -offsetY);

   return sBG;
}

int BG::getX() {
	return offsetX;
}

int BG::getY() {
	return offsetY;
}