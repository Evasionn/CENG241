#include "CargoShip.h"

CargoShip::CargoShip() { setName(""); setYear(0); this->tonnage = 0; }
CargoShip::CargoShip(string name, int year, int tonnage)
{
	setName(name);
	setYear(year);
	this->tonnage = tonnage;
}

void CargoShip::setTonnage(int tonnage) { this->tonnage = tonnage; }
int CargoShip::getTonnage() { return this->tonnage; }
void CargoShip::display() { cout << getName() << "\t" << getYear() << "\t" << this->tonnage << endl; }
