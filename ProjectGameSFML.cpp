// ProjectGameSFML.cpp
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;

int main()
{
   RenderWindow window(VideoMode(900, 600), "Game");

   Image heroimg;
   heroimg.loadFromFile("igrok.png");
  

   Texture herotexture;
   herotexture.loadFromImage(heroimg);
  

   Sprite herosprite;
   herosprite.setTexture(herotexture);
   herosprite.setTextureRect(IntRect(15,8,30,51));// 1 - откуда начинаем(Начало)  2 - больше вниз/меньше вверх (Y) 3 - ширина(y) 4 - удлиняет картинку вниз или вверх(Y)
   herosprite.setPosition(450, 300);

   
 
  
   // 1 - откуда начинаем(Начало)  2 - больше вниз/меньше вверх (Y) 3 - ширина(y) 4 - удлиняет картинку вниз или вверх(Y)


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

       if ((Keyboard::isKeyPressed(Keyboard::Left) || (Keyboard::isKeyPressed(Keyboard::A)))) 
       { 
          
          
         
           Frame += 0.005 * time;  

           if (Frame > 8)
           {
               Frame = 0;
           }
           herosprite.setTextureRect(IntRect(32 * int(Frame)+ 18+30, 131, -30, 51));
           herosprite.move(-0.1 * time, 0);
       }

       if ((Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D)))) 
       {
           
           Frame += 0.005 * time;
           if (Frame > 8)
           {
                Frame = 0;
           }
               
           herosprite.setTextureRect(IntRect(32 * int(Frame) + 18, 131, 30, 51));
           herosprite.move(0.1 * time, 0);
       }


       if ((Keyboard::isKeyPressed(Keyboard::Up) || (Keyboard::isKeyPressed(Keyboard::W)))) {
           Frame += 0.005 * time; 
           if (Frame > 3) Frame -= 3; 
           herosprite.setTextureRect(IntRect(32 * int(Frame)+ 18, 131, 30, 51));
           herosprite.move(0, -0.1 * time);
       }

       if ((Keyboard::isKeyPressed(Keyboard::Down) || (Keyboard::isKeyPressed(Keyboard::S)))) {
           Frame += 0.005 * time; 
           if (Frame > 3) Frame -= 3; 
           herosprite.setTextureRect(IntRect(96 * int(Frame), 0, 96, 96)); 
           herosprite.move(0, 0.1 * time);
       }

       
      

       

       window.clear();
       window.draw(herosprite);
       window.display();
   }
    



}

