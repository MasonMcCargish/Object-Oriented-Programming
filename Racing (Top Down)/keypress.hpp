#pragma once

struct Keypress
{
	bool Up, Right, Down, Left;

	Keypress() {
		Up = false;
		Right = false;
		Down = false;
		Left = false;
	}

	void detectKey();
};