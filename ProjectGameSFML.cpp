// ProjectGameSFML.cpp
#include "Entity.h"

bool isAnyKeyPressed()
{
    for (int i = 0; i < Keyboard::KeyCount; ++i)
    {
        if (Keyboard::isKeyPressed(static_cast<Keyboard::Key>(i)))
            return false;
    }
    return true;
}

int main()
{
   RenderWindow window(VideoMode(900, 600), "Game");

   Player Hero("igrok.png", 104, 70, 30, 51);


   Image heroimg;
   heroimg.loadFromFile("igrok.png");
  

   Texture herotexture;
   herotexture.loadFromImage(heroimg);
  

   Sprite herosprite;
   herosprite.setTexture(herotexture);
   herosprite.setTextureRect(IntRect());
   herosprite.setPosition(450, 300);

   
 
  



   float Frame = 0;
   Clock clock;
  

   while (window.isOpen())
   {
       float time = clock.getElapsedTime().asMicroseconds();
       clock.restart();
       time = time / 800;
       Event event;
       while (window.pollEvent(event))
       {
           if (event.type == Event::Closed)
               window.close();
       }

      /* if (isAnyKeyPressed())
       {
           Frame += 0.005 * time;

           if (Frame > 13)
           {
               Frame = 0;
           }
           herosprite.setTextureRect(IntRect(32 * int(Frame) + 18, 9, 33, 51));
           
       }*/
       
      /*if ((Keyboard::isKeyPressed(Keyboard::A))) 
       { 
          
          
         
           Frame += 0.005 * time;  

           if (Frame > 8)
           {
               Frame = 0;
           }
           herosprite.setTextureRect(IntRect(32 * int(Frame)+ 18 +30, 131, -30, 51));
           herosprite.move(-0.1 * time, 0);
       }

       if ((Keyboard::isKeyPressed(Keyboard::D))) 
       {
           
           Frame += 0.005 * time;
           if (Frame > 8)
           {
                Frame = 0;
           }
               
           herosprite.setTextureRect(IntRect(32 * int(Frame) + 18, 131, 30, 51));
           herosprite.move(0.1 * time, 0);
       }

       if ((Keyboard::isKeyPressed(Keyboard::A) && (Keyboard::isKeyPressed(Keyboard::D))))
       {

           herosprite.setTextureRect(IntRect(104, 70, 30, 51));
       }*/

       if ((Keyboard::isKeyPressed(Keyboard::A)))
       {
           Hero.napravlenie = 1;
           Hero.speed = 0.1;
           Frame += 0.005 * time;

           if (Frame > 8)
           {
               Frame = 0;
           }

           Hero.sprite.setTextureRect(IntRect(32 * int(Frame) + 18 + 30, 131, -30, 51));
           
       }

       if ((Keyboard::isKeyPressed(Keyboard::D)))
       {

           Frame += 0.005 * time;
           if (Frame > 8)
           {
               Frame = 0;
           }

           herosprite.setTextureRect(IntRect(32 * int(Frame) + 18, 131, 30, 51));
           herosprite.move(0.1 * time, 0);
       }

       if ((Keyboard::isKeyPressed(Keyboard::A) && (Keyboard::isKeyPressed(Keyboard::D))))
       {

           herosprite.setTextureRect(IntRect(104, 70, 30, 51));
       }

       

      

       Hero.walking(time);
      

       

       window.clear();
       window.draw(herosprite);
       window.draw(Hero.sprite);
       window.display();
   }
    



}

