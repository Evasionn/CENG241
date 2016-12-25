#include "Ship.h"


int Ship::getYear() { return this->year; }
void Ship::setYear(int y) { this->year = y; }
string Ship::getName() { return this->name; }
void Ship::setName(string n) { this->name = n; }
void Ship::display() { cout << name << "\t" << year << endl; }
