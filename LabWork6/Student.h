#pragma once
#include <iostream>
#include <string>
#include "Course.h"

using namespace std;
class Student
{
private:
	string name;
	string surname;
	int number;
	Course cList[6];
	int cSize;
public:
	Student();
	Student(string, string, int);
	string getName();
	string getSurname();
	int getNumber();
	void setName(string);
	void setSurname(string);
	void setNumber(int);
	void display();
	void addCourse(Course);
	void listOfCourse();
	void removeCourse(int);
	int findCourse(string);
};

