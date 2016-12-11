#include "complex.h"


complex complex::operator+(complex x)
{
	complex result(real+x.real,img+x.img);
	return result;
}

complex complex::operator+(double x)
{
	complex result(real+x , img);
	return result;
}

complex complex::operator-(complex x)
{
	complex result(real-x.real,img-x.img);
	return result;
}

complex complex::operator-(double x)
{
	complex result(real-x,img);
	return result;
}

complex complex::operator*(complex x)
{
	complex result((real*x.real) - (img*x.img), (real*x.img) + (img * x.real));
	return result;
}

complex complex::operator*(double x)
{
	complex result(real*x,img*x);
	return result;
}

complex complex::operator/(complex x)
{
	complex result(((real*x.real + img*x.img) / (x.real*x.real + x.img*x.img)), ((-real*x.img + x.real*img) / (x.real*x.real + x.img*x.img)));
	return result;
}

complex complex::operator/(double x)
{
	complex result(real/x,img/x);
	return result;
}

double complex::operator~()
{
	double result;
	result = sqrt(real*real + img*img);
	return result;
}

bool complex::operator==(complex x)
{
	return real == x.real && img == x.img ? true : false;
}
bool complex::operator!=(complex x)
{
	return !complex::operator==(x); 	//return real != x.real && img != x.img ? true : false;
}