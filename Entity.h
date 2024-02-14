#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;

class EntityPL
{
public:
	float x{ 0.f }, y{ 0.f }, w{ 0.f }, h{ 0.f }, dx{ 0.f }, dy{ 0.f }, speed{0.f};

	int napravlenie{0};

	String file;

	Image image;

	Texture texture;

	Sprite sprite;

};

class Player : public EntityPL
{
public:
	Player(String F, int X, int Y, float W, float H)
	{
		file = F;
		w = W; 
		h = H;

		image.loadFromFile(file);
		texture.loadFromImage(image);
		sprite.setTexture(texture);

		x = X; 
		y = Y;

		sprite.setTextureRect(IntRect(w, h, w, h));
	}

	void walking(float time)
	{
		switch (napravlenie)
		{
		case 0:
			dx = speed; 
			dy = 0;
			break;
		case 1:
			dx = -speed;
			dy = 0;
			break;
		case 2:
			dx = 0;
			dy = speed;
		case 3:
			dx = 0;
			dy = -speed;
		}

		x += dx * time;
		x += dy * time;

		speed = 0;
		sprite.setPosition(x, y);

	}




};