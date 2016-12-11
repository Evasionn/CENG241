#pragma once
#include <iostream>
#include <cmath>
using namespace std;
class complex
{
public:
	double real, img;
	complex(double x=0, double y=0) :real(x), img(y) {};
	
	complex operator+(complex);
	complex operator+(double);
	complex operator-(complex);
	complex operator-(double);
	complex operator*(complex);
	complex operator*(double);
	complex operator/(complex);
	complex operator/(double);
	double operator~();

	bool operator==(complex);
	bool operator!=(complex);

	friend complex operator+(double x, complex y);
	friend complex operator-(double x, complex y);
	friend complex operator*(double x, complex y);
	friend complex operator/(double x, complex y);
	friend ostream& operator<<(ostream& x, complex y);
};

