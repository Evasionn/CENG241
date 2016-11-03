#pragma once
#include <iostream>
#include <string>
using namespace std;
class Course
{
private:
	string code;
	string cName;
public:
	string getCode();
	string getcName();
	void setCode(string);
	void setCName(string);
	void display();
};

