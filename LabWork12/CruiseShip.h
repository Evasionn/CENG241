#pragma once
#include "Ship.h"
class CruiseShip :
	public Ship
{
private:
	int passengers;
public:
	CruiseShip();
	CruiseShip(string,int,int,double);
	int getPassangers();
	void setPassengers(int);
	void display();
	double getCost();
};

