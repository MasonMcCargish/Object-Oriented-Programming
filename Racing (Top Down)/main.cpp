#include "car.hpp"

#include <cmath>

#include <SFML/Graphics.hpp>
using namespace sf;

int
main()
{
   RenderWindow app(VideoMode(640, 480), "Car Racing Game!");
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
   const int N = 5;
   Car car[N];
   for (int i = 0; i < N; i++) {
      car[i].setPos(300 + i * 50, 1700 + i * 80);
      car[i].setSpeed(7 + i);
   }

   int offsetX = 0, offsetY = 0;

   bool Up = 0, Right = 0, Down = 0, Left = 0;

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
         car[0].accellerate();

      if (Down)
      	car[0].brake();
\
      if (!Up && !Down)
      	car[0].coast();

      // steers the user car if the inputs are detected
      if (Right)
         car[0].turnR();
      if (Left)
         car[0].turnL();

      // allows the cars to move
      for (int i = 0; i < N; i++)
         car[i].move();
      // makes the AI find their next point to drive to
      for (int i = 1; i < N; i++)
         car[i].findTarget();

      // collision
      for (int i = 0; i < N; i++)
         for (int j = 0; j < N; j++) {
            int dx = 0, dy = 0;
            while (dx * dx + dy * dy < 4 * R * R) {
               car[i].x += dx / 10.0;
               car[i].x += dy / 10.0;
               car[j].x -= dx / 10.0;
               car[j].y -= dy / 10.0;
               dx = car[i].x - car[j].x;
               dy = car[i].y - car[j].y;
               if (!dx && !dy)
                  break;
         }
      }

      // makes anything not covered by the background image white
      app.clear(Color::White);

      // makes the background pan with the player's car
      if (car[0].x > 320)
         offsetX = car[0].x - 320;
      if (car[0].y > 240)
         offsetY = car[0].y - 240;

      // draws the background
      sBackground.setPosition(-offsetX, -offsetY);
      app.draw(sBackground);

      // defines the color for each car
      Color colors[10] = {
         Color::Red, Color::Green, Color::Magenta, Color::Blue, Color::White
      };

      // draws the Cars
      for (int i = 0; i < N; i++) {
         sCar.setPosition(car[i].x - offsetX, car[i].y - offsetY);
         sCar.setRotation(car[i].angle * 180 / 3.141593);
         sCar.setColor(colors[i]);
         app.draw(sCar);
      }

      app.display();
   }

   return 0;
}
