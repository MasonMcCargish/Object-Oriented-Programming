#pragma once

#include <SFML/Graphics.hpp>
using namespace sf;

class BG
{
public:
	BG(){
		offsetX = 0;
		offsetY = 0;

  		t.loadFromFile("images/background.png");
  		t.setSmooth(true);
  		sBG.setTexture(t);
   	sBG.scale(2, 2);
	}

	Sprite pan(int, int);
	int getX();
	int getY();

private:
	int offsetX, offsetY;

	Texture t;
	Sprite sBG;
};