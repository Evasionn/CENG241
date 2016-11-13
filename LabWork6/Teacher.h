#pragma once
#include <iostream>
#include <string>
#include "Course.h"
using namespace std;
class Teacher
{
private:
	string name;
	string surname;
	int rNumber;
	Course cList[3];
	int cSize;
public:
	Teacher();
	Teacher(string, string, int);
	string getName();
	string getSurname();
	int getNumber();
	void setName(string);
	void setSurname(string);
	void setRNumber(int);
	void display();
	void addCourse(Course);
	void listOfCourse();
	void removeCourse(int);
};

