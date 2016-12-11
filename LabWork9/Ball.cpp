#include "Ball.h"


Ball::Ball()
{
	velocity = 150;
	xPos = 40;
	yPos = 40;
	radius = 10;
}

Ball::Ball(int xPos, int yPos, int radius, int velocity)
{
	this->xPos = xPos;
	this->yPos = yPos;
	this->radius = radius;
	this->velocity = velocity;
}


int Ball::getXPos()
{
	return xPos;
}
int Ball::getYPos()
{
	return yPos;
}
int Ball::getRadius()
{
	return radius;
}
int Ball::getVelocity()
{
	return velocity;
}
void Ball::setXPos(int xPos)
{
	this->xPos = xPos;
}
void Ball::setYPos(int yPos)
{
	this->yPos = yPos;
}
void Ball::setVelocity(int velocity)
{
	if (velocity < 5) velocity = 0;
	this->velocity = velocity;
}
void Ball::setRadius(int radius)
{
	this->radius = radius;
}

