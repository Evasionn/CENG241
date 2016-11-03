#pragma once
#include <iostream>
#include <string>
using namespace std;
class Student
{
private:
	string name;
	string surname;
	int number;
public:
	string getName();
	string getSurname();
	int getNumber();
	void setName(string);
	void setSurname(string);
	void setNumber(int);
	void display();

};

