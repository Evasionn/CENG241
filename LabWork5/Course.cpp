#include "Course.h"


string Course::getcName()
{
	return cName;
}

string Course::getCode()
{
	return code;
}

void Course::setCName(string cName)
{
	this->cName = cName;
}

void Course::setCode(string code)
{
	this->code = code;
}

void Course::display()
{
	cout << code << " " << cName << endl;
}