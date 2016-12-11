#include "Snake.h"



Snake::Snake()
{
	nodes = new Ball[3];
	length = 3;
	score = 0;
}


Snake::~Snake()
{
	delete[] nodes;
	length = 0;
	score = 0;
}

Ball Snake::getHead()
{
	return nodes[0];
}
void Snake::move(int x, int y)
{
	
	for (int i = length-1; i > 0; i--)
	{
		nodes[i] = nodes[i - 1];
	}
	nodes[0].setXPos(x);
	nodes[0].setYPos(y);
}
void Snake::addNode(Ball newNode)
{
	nodes = (Ball *)realloc(nodes, sizeof(Ball)*(length + 1));
	nodes[length] = nodes[length - 1];
	length++;
}
void Snake::drawAll()
{
	for (int i = 0; i < length; i++)
	{
		usePen(PS_SOLID, 1, RGB(0, 0, 0));
		drawCircle(nodes[i].getXPos(), nodes[i].getYPos(), 10);
		
	}
	Sleep(getHead().getVelocity());
	for (int i = 0; i < length; i++)
	{
		usePen(PS_SOLID, 1, RGB(255, 255, 255));
		drawCircle(nodes[i].getXPos(), nodes[i].getYPos(), 10);
	}
}

bool Snake::isScore(Food x)
{
	int foodX = x.getXPos();
	int foodY = x.getYPos();

	int headX = getHead().getXPos();
	int headY = getHead().getYPos();

	if (headX  == foodX && headY == foodY) return true;
	if (headX == foodX + 10 && headY == foodY + 10) return true;
	return false;

}

void Snake::incScore() { score += 10; }

bool Snake::checkWall()
{
	int headX = getHead().getXPos();
	int headY = getHead().getYPos();
	
	if (headX + 10 >= 570 || headY + 10 >= 550 || headX - 10 <= 10 || headY - 10 <= 10)
	{
		endGame();
		return true;
	}

	return false;
}

void Snake::drawLast()
{
	for (int i = 0; i < length; i++)
	{
		usePen(PS_SOLID, 1, RGB(0, 0, 0));
		drawCircle(nodes[i].getXPos(), nodes[i].getYPos(), 10);
	}
}

int Snake::getScore() { return score;  }

bool Snake::hitItself(int dontCare)
{
	if (dontCare == 1)return false;
	int headX = nodes[0].getXPos();
	int headY = nodes[0].getYPos();
	
	for (int i = 5; i < length; i++)
	{
		if (headY  == nodes[i].getYPos()  && headX == nodes[i].getXPos())
		{
			endGame();
			return true;
		}
		
	}
	return false;
	
}

void Snake::endGame()
{
	cout << "Game is over.  Your score is: " << getScore() << endl;
	drawLast();
}

bool Snake::checkFoodOnMe(Food x)
{
	int foodX = x.getXPos();
	int foodY = x.getYPos();

	for (int i = 0; i < length; i++)
	{
		if (nodes[i].getXPos() == foodX && nodes[i].getYPos() == foodY) return true;
		if (nodes[i].getXPos() == foodX + 10 && nodes[i].getYPos() == foodY + 10) return true;
	}

	return false;
}