#include "CruiseShip.h"

CruiseShip::CruiseShip() { setName(""); setYear(0); this->passengers = 0; setDistance(0); }
CruiseShip::CruiseShip(string name, int year, int passengers, double distance)
{
	setName(name);
	setYear(year);
	this->passengers = passengers;
	setDistance(distance);
}

void CruiseShip::setPassengers(int passengers) { this->passengers = passengers; }
int CruiseShip::getPassangers() { return this->passengers; }
void CruiseShip::display() { cout << getName() << "\t" << getYear() << "\t" << this->passengers << "\t" << getCost() << endl; }
double CruiseShip::getCost() { return getDistance()*1.5; }