#pragma once
#include <string>
#include <iostream>
using namespace std;
class Ship
{
private: 
	int year;
	string name;
	double distance;
public:
	Ship(int y = 0, string n = "", double dis=0) :year(y), name(n), distance(dis) {}

	int getYear();
	void setYear(int);
	string getName();
	void setName(string);
	void display();
	virtual double getCost();
	void setDistance(double);
	double getDistance();
};

