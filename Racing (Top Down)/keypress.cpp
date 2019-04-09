#include "keypress.hpp"
#include <SFML/Graphics.hpp>

using namespace sf;

void Keypress::detectKey() {
	Up = Keyboard::isKeyPressed(Keyboard::Up);
   Right = Keyboard::isKeyPressed(Keyboard::Right);
   Down = Keyboard::isKeyPressed(Keyboard::Down);
   Left = Keyboard::isKeyPressed(Keyboard::Left);
}
