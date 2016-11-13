#include "Student.h"

Student::Student()
{
	name = "";
	surname = "";
	number = -1;
	cSize = 0;
}

Student::Student(string name, string surname, int number)
{
	this->name = name;
	this->surname = surname;
	this->number = number;
	cSize = 0;
}

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

void Student::addCourse(Course c)
{
	if (cSize == 6) return;
	cList[cSize] = c;
	cSize++;
}

void Student::listOfCourse()
{
	for (int i = 0; i < cSize; i++)
	{
		cout << (i + 1) << ") ";
		cList[i].display();
	}
}

void Student::removeCourse(int index)
{
	cList[index] = cList[cSize];
	cSize--;

}

int Student::findCourse(string code)
{
	for (int i = 0; i < cSize; i++)
	{
		if (code == cList[i].getCode()) return 1;
	}
	return 0;
}