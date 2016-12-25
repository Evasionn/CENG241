#pragma once
#include <string>
#include <iostream>
using namespace std;
class Ship
{
private: 
	int year;
	string name;
public:
	Ship(int y = 0, string n = "") :year(y), name(n) {}

	int getYear();
	void setYear(int);
	string getName();
	void setName(string);
	void display();
};

