#include "Teacher.h"

string Teacher::getName()
{
	return name;
}

string Teacher::getSurname()
{
	return name;
}

int Teacher::getNumber()
{
	return rNumber;
}

void Teacher::setName(string name)
{
	this->name = name;
}

void Teacher::setSurname(string surname)
{
	this->surname = surname;
}

void Teacher::setRNumber(int number)
{
	this->rNumber = number;
}

void Teacher::display()
{
	cout << name << " " << " " << surname << " " << rNumber << endl;
}