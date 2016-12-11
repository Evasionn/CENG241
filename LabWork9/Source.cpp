
#include "Snake.h"
#include <conio.h>
int main()
{
	Food * theFood = new Food;
	Snake theSnake;
	char ch=0,prev=0;
	int dontCare = 0;
	setWindowSize(600, 600);

	drawRectangle(10, 0, 570, 550);

	while (theSnake.checkFoodOnMe(*theFood))
	{
		delete theFood;
		theFood = new Food;
	}
	
	while (!theSnake.checkWall() && !theSnake.hitItself(dontCare)){
		
		dontCare = 0;
		theSnake.drawAll();


		if (_kbhit())
		{
			ch = _getch();
		}
		if (ch == 'w' && prev != 's') {
			theSnake.move(theSnake.getHead().getXPos(), theSnake.getHead().getYPos() - 10 * 2);
			prev = ch;
		}
		else if (ch == 's' && prev != 'w')
		{
			theSnake.move(theSnake.getHead().getXPos(), theSnake.getHead().getYPos() + 10 * 2);
			prev = ch;
		}
		else if (ch == 'a' && prev != 'd')
		{
			theSnake.move(theSnake.getHead().getXPos() - 10 * 2, theSnake.getHead().getYPos());
			prev = ch;
		}
		else if (ch == 'd' && prev != 'a') {
			theSnake.move(theSnake.getHead().getXPos() + 10 * 2, theSnake.getHead().getYPos());
			prev = ch;
		}
		
		ch = prev;
		usePen(PS_SOLID, 1, RGB(0, 0, 0));
		drawRectangle(theFood->getXPos(), theFood->getYPos(), theFood->getXPos() + 10, theFood->getYPos() + 10);
		if (theSnake.isScore(*theFood))
		{
			theSnake.incScore();
			theSnake.addNode(theSnake.getHead());
			usePen(PS_SOLID, 1, RGB(255, 255, 255));
			drawRectangle(theFood->getXPos(), theFood->getYPos(), theFood->getXPos() + 10, theFood->getYPos() + 10);
			do {
				delete theFood;
				theFood = new Food;
			} while (theSnake.checkFoodOnMe(*theFood));
			dontCare = 1;
		}
	}


	


	getchar();
}
