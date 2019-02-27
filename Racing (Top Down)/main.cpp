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
      car[i].x = 300 + i * 50;
      car[i].y = 1700 + i * 80;
      car[i].speed = 7 + i;
   }
   
   // defines the properties of the car
   float speed = 0, angle = 0;
   float maxSpeed = 12.0;
   float acc = 0.2, dec = 0.3;
   float turnSpeed = 0.08;

   int offsetX = 0, offsetY = 0;

   //MAIN GAME LOOP
   while (app.isOpen()) {
      Event e;
      while (app.pollEvent(e)) {
         if (e.type == Event::Closed)
            app.close();
      }

      // detects keyboard inputs
      bool Up = 0, Right = 0, Down = 0, Left = 0;
      if (Keyboard::isKeyPressed(Keyboard::Up))
         Up = 1;
      if (Keyboard::isKeyPressed(Keyboard::Right))
         Right = 1;
      if (Keyboard::isKeyPressed(Keyboard::Down))
         Down = 1;
      if (Keyboard::isKeyPressed(Keyboard::Left))
         Left = 1;

      // car movement
      if (Up && speed < maxSpeed) {
         if (speed < 0)
            speed += dec;
         else
            speed += acc;
      }

      if (Down && speed > -maxSpeed) {
         if (speed > 0)
            speed -= dec;
         else
            speed -= acc;
      }

      // defines coasting
      if (!Up && !Down) {
         if (speed - dec > 0)
            speed -= dec;
         else if (speed + dec < 0)
            speed += dec;
         else
            speed = 0;
      }

      // steers the user car if the inputs are detected
      if (Right && speed != 0)
         angle += turnSpeed * speed / maxSpeed;
      if (Left && speed != 0)
         angle -= turnSpeed * speed / maxSpeed;

      // sets the angle and speed of the user car
      car[0].speed = speed;
      car[0].angle = angle;

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
