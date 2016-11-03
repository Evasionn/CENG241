#pragma once
#include <iostream>
#include <string>
using namespace std;
class Teacher
{
private:
	string name;
	string surname;
	int rNumber;
public:
	string getName();
	string getSurname();
	int getNumber();
	void setName(string);
	void setSurname(string);
	void setRNumber(int);
	void display();

};

