#include "car.hpp"

#include <cmath>
#include <iostream>


#include <SFML/Graphics.hpp>
using namespace sf;


int
main()
{
   RenderWindow app(VideoMode(640, 480), "DORIFUTO!");
   app.setFramerateLimit(60);

   Texture t1, t2, t3;
   t1.loadFromFile("images/background.png");
   t2.loadFromFile("images/car.png");
   t1.setSmooth(true);
   t2.setSmooth(true);

   Sprite sBackground(t1), sCar(t2);
   sBackground.scale(2, 2);

   sCar.setOrigin(22, 22);
   float R = 22;

   // creates the cars
   // car[0] is the user car and the rest are AI

   Car car;
   car.setPos(300, 1700);
   car.setSpeed(10);

   int offsetX = 0, offsetY = 0;

   bool Up = 0, Right = 0, Down = 0, Left = 0;

   int count = 0;

   //MAIN GAME LOOP
   while (app.isOpen()) {
      Event e;
      while (app.pollEvent(e)) {
         if (e.type == Event::Closed)
            app.close();
      }

      // detects keyboard inputs
      Up = Keyboard::isKeyPressed(Keyboard::Up);
      Right = Keyboard::isKeyPressed(Keyboard::Right);
      Down = Keyboard::isKeyPressed(Keyboard::Down);
      Left = Keyboard::isKeyPressed(Keyboard::Left);

      // car movement
      if (Up)
         car.accellerate();
      if (Down)
      	car.brake();
      if (!Up && !Down)
      	car.coast();
      if (Right)
         car.turnR();
      if (Left)
         car.turnL();

      // allows the cars to move
      car.move();

      // collision
      // for (int i = 0; i < N; i++)
      //    for (int j = 0; j < N; j++) {
      //       int dx = 0, dy = 0;
      //       while (dx * dx + dy * dy < 4 * R * R) {
      //          car[i].x += dx / 10.0;
      //          car[i].x += dy / 10.0;
      //          car[j].x -= dx / 10.0;
      //          car[j].y -= dy / 10.0;
      //          dx = car[i].x - car[j].x;
      //          dy = car[i].y - car[j].y;
      //          if (!dx && !dy)
      //             break;
      //    }
      // }

      // makes anything not covered by the background image white
      app.clear(Color::White);

      // makes the background pan with the player's car
      if (car.x > 320)
         offsetX = car.x - 320;
      if (car.y > 240)
         offsetY = car.y - 240;

      // draws the background
      sBackground.setPosition(-offsetX, -offsetY);
      app.draw(sBackground);

      // defines the color for each car
      Color colors[10] = {
         Color::Red, Color::Green, Color::Magenta, Color::Blue, Color::White
      };

      // draws the Cars

      sCar.setPosition(car.x - offsetX, car.y - offsetY);
      sCar.setRotation(car.angle * 180 / 3.141593);
      sCar.setColor(Color::Red);
      app.draw(sCar);

      app.display();
   }

   return 0;
}
