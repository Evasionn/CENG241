#include "Student.h"

string Student::getName() 
{
	return name;
}

string Student::getSurname()
{
	return name;
}

int Student::getNumber()
{
	return number;
}

void Student::setName(string name)
{
	this->name = name;
}

void Student::setSurname(string surname)
{
	this->surname = surname;
}

void Student::setNumber(int number)
{
	this->number = number;
}

void Student::display()
{
	cout << name << " " << " " << surname << " " << number << endl;
}