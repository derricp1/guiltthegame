#include "../headers/Player.h"
#include <iostream>

Player::Player(int x, int y, SDL_Color *initCol)
{
	shape->x = x;
	shape->y = y;
	shape->h = 100;
	shape->w = 100;
	
	if (!initCol)
	{
		color->r = 150;
		color->g = 150;
		color->b = 150;
	}
	else
		color = initCol;
}


Player::Player(const Player& rhs)
{
	shape->x = rhs.shape->x;
	shape->y = rhs.shape->x;
	shape->h = rhs.shape->h;
	shape->w = rhs.shape->w;
	
	color->r = rhs.color->r;
	color->g = rhs.color->g;
	color->b = rhs.color->b;
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


void Player::moveup()
{
	shape->y -= moveFactor;
	cout << "moved up" << endl;
}


void Player::movedown()
{
	shape->y += moveFactor;
	cout << "moved down" << endl;
}


void Player::moveleft()
{
	shape->x -= moveFactor;
	cout << "Moved left" << endl;
}


void Player::moveright()
{
	shape->x += moveFactor;
	cout << "Moved right" << endl;
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
