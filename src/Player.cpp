#include "../headers/Player.h"
#include <iostream>

Player::Player(int x, int y, SDL_Color *initCol)
{
	shape = new SDL_Rect;
	shape->x = x;
	shape->y = y;
	shape->h = 100;
	shape->w = 100;
	
	if (!initCol)
	{
		color = new SDL_Color;
		color->r = 150;
		color->g = 150;
		color->b = 150;
	}
	else
		color = initCol;
}


Player::Player(const Player& rhs)
{
	shape = new SDL_Rect;
	shape->x = rhs.shape->x;
	shape->y = rhs.shape->x;
	shape->h = rhs.shape->h;
	shape->w = rhs.shape->w;
	
	color = new SDL_Color;
	color->r = rhs.color->r;
	color->g = rhs.color->g;
	color->b = rhs.color->b;
}


Player::~Player()
{
	delete shape;
	delete color;
}


Player& Player::operator= (const Player& rhs)
{
	if (this==&rhs)
		return *this;
	else
	{
		shape->x = rhs.shape->x;
		shape->y = rhs.shape->x;
		shape->h = rhs.shape->h;
		shape->w = rhs.shape->w;
		
		color->r = rhs.color->r;
		color->g = rhs.color->g;
		color->b = rhs.color->b;
		
		return *this;
	}
}


void Player::moveup(int bound)
{
	if (shape->y > bound)
	{
		shape->y -= moveFactor;
		cout << "moved up" << endl;
	}
	else 
		cout << "Cannot move up; bounds reached" << endl;
}


void Player::movedown(int bound)
{
	if (shape->y + shape->h < bound)
	{
		shape->y += moveFactor;
		cout << "moved down" << endl;
	}
	else
		cout << "Cannot move down; bounds reached" << endl;
}


void Player::moveleft(int bound)
{
	if (shape->x > bound)
	{
		shape->x -= moveFactor;
		cout << "Moved left" << endl;
	}
	else
		cout << "Cannot move left; bounds reached" << endl;
}


void Player::moveright(int bound)
{
	if (shape->x + shape->w < bound)
	{
		shape->x += moveFactor;
		cout << "Moved right" << endl;
	}
	else
		cout << "Cannot move right; bounds reached" << endl;
}


SDL_Rect* Player::getShape() const
{
	return shape;
}


SDL_Color* Player::getColor() const
{
	return color;
}


Uint32 Player::mapColor(SDL_Surface *screen) const
{
	return SDL_MapRGB(screen->format, color->r,
						color->g, color->b);
}
