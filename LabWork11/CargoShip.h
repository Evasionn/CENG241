#pragma once
#include "Ship.h"
class CargoShip :
	public Ship
{
private:
	int tonnage;
public:
	CargoShip();
	CargoShip(string, int, int);
	void setTonnage(int);
	int getTonnage();
	void display();
};

