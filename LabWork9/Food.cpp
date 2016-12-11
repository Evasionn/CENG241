#include "Food.h"



Food::Food()
{
	int op = 20;
	srand(time(NULL));
	do {
		xPos = rand() % (10);
		yPos = rand() % (10);
	} while (xPos == 0 || yPos == 0);
	xPos *= op;
	yPos *= op;
	xPos += 10;
	yPos += 10;
}

int Food::getXPos() { return xPos; }
int Food::getYPos() { return yPos; }
