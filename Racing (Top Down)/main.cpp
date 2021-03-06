#include "car.hpp"
#include "keypress.hpp"
#include "bg.hpp"
#include "score.hpp"
#include "wall.hpp"

#include <cmath>
#include <iostream>


#include <SFML/Graphics.hpp>
using namespace sf;


struct EventS
{
	Window* app;


	EventS(Window& w): app(&w)
	{ }

	void checkEvent() {
		Event e;
		while (app->pollEvent(e)) {
		   switch(e.type) {
		      case Event::Closed: app->close();
		   }
		}
	}
};

int
main()
{
   RenderWindow app(VideoMode(640, 480), "DORIFUTO!");
   app.setFramerateLimit(60);

   //car and background sprites for drawing later
   Sprite sCar;
   Sprite sBackground;

   // creates the car
   Car car;
   car.setPos(300, 1700);
   car.setSpeed(10);

   Score s;
   Keypress key;
   BG track;

   Font f;
   Text t;
   f.loadFromFile("arial.ttf");
   t.setString("Score: ");
   t.setFont(f);
   t.setCharacterSize(50);

   Wall w {0,0,40,1000};

   EventS e{app};
   //MAIN GAME LOOP
   while (app.isOpen()) {
   	e.checkEvent();
   	
      // detects keyboard inputs
      key.detectKey();

      // car movement
      if (key.Up)
         car.accellerate();
      if (key.Down)
      	car.brake();
      if (!key.Up && !key.Down)
      	car.coast();
      if (key.Right)
         car.turnR();
      if (key.Left)
         car.turnL();

      // allows the cars to move
      s = car.move();

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

      std::cout << w.collide(car) << '\n';

      // makes anything not covered by the background image white
      app.clear(Color::White);

      //draws the background
      sBackground = track.pan(car.x, car.y);
      app.draw(sBackground);

      // draws the Car
      sCar = car.mvSprite(track.getX(), track.getY());
      app.draw(sCar);

      t = s.print();
      app.draw(t);

      app.display();
   }

   return 0;
}
