#pragma once
using namespace std;
class Ball
{
private:
	int xPos;
	int yPos;
	int radius;
	int velocity;
public:
	Ball();
	Ball(int, int, int, int);
	int getXPos();
	int getYPos();
	int getVelocity();
	int getRadius();
	void setXPos(int);
	void setYPos(int);
	void setVelocity(int);
	void setRadius(int);

};

