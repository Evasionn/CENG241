#include "Ball.h"



Ball::Ball()
{
	velocity = 1000;
	xPos = 50;
	yPos = 50;
	radius = 20;
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
	this->velocity = velocity;
}
void Ball::setRadius(int radius)
{
	this->radius = radius;
}