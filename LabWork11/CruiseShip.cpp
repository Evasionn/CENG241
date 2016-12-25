#include "CruiseShip.h"

CruiseShip::CruiseShip() { setName(""); setYear(0); this->passengers = 0; }
CruiseShip::CruiseShip(string name, int year, int passengers)
{
	setName(name);
	setYear(year);
	this->passengers = passengers;
}

void CruiseShip::setPassengers(int passengers) { this->passengers = passengers; }
int CruiseShip::getPassangers() { return this->passengers; }
void CruiseShip::display() { cout << getName() << "\t" << getYear() << "\t" << this->passengers << endl; }
