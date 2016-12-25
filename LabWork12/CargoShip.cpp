#include "CargoShip.h"

CargoShip::CargoShip() { setName(""); setYear(0); this->tonnage = 0; setDistance(0); }
CargoShip::CargoShip(string name, int year, int tonnage, double d)
{
	setName(name);
	setYear(year);
	this->tonnage = tonnage;
	setDistance(d);
}

void CargoShip::setTonnage(int tonnage) { this->tonnage = tonnage; }
int CargoShip::getTonnage() { return this->tonnage; }
void CargoShip::display() { cout << getName() << "\t" << getYear() << "\t" << this->tonnage << "\t" << getCost() << endl; }
double CargoShip::getCost() { return getDistance() * 2; }

