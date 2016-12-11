#pragma once
#include "Food.h"
#include "Ball.h"
#include "SimpleDraw.h"
class Snake
{
private:
	Ball * nodes;
	int length;
	int score;
public:
	Snake();
	Ball getHead();
	void move(int,int);
	void addNode(Ball);
	void drawAll();
	bool isScore(Food);
	void incScore();
	bool checkWall();
	void drawLast();
	int getScore();
	bool hitItself(int);
	void endGame();
	bool checkFoodOnMe(Food);
	~Snake();
};

