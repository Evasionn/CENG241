#include "Teacher.h"

Teacher::Teacher()
{
	name = "";
	surname = "";
	rNumber = -1;
	cSize = 0;
}

Teacher::Teacher(string name, string surname, int number)
{
	this->name = name;
	this->surname = surname;
	rNumber = number;
	cSize = 0;
}

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

void Teacher::addCourse(Course c)
{
	if (cSize == 3) return;
	cList[cSize] = c;
	cSize++;
}

void Teacher::listOfCourse()
{
	for (int i = 0; i < cSize; i++)
	{
		cout << (i + 1) << ") ";
		cList[i].display();
	}
}

void Teacher::removeCourse(int index)
{
	cList[index] = cList[cSize];
	cSize--;
}
