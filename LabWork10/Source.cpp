#include "complex.h"

complex operator+(double x, complex y)
{
	complex result;

	result.real = x + y.real;
	result.img = y.img;

	return result;
}

complex operator-(double x, complex y)
{
	complex result;
	result.real = x - y.real;
	result.img = -y.img;
	
	return result;
}

complex operator*(double x, complex y)
{
	complex result;

	result.real = x*y.real;
	result.img = x*y.img;
	
	return result;
}

complex operator/(double x, complex y)
{
	complex result;

	result.real = x / y.real;
	result.img = x / y.img;

	return result;
}

ostream& operator<<(ostream& x, complex y)
{
	x << y.real << " " << y.img <<"i" << endl;

	return x;
}
int main()
{
	complex a(5, 3);
	complex b(2, 1);
	complex result;
	
	cout << "a= " << a;
	cout << "b= " << b;
	
	result = a + b;
	cout << "Sum= " << result;
	result = a - b;
	cout << "Sub= " << result;
	result = a*b;
	cout << "Mul= " << result;
	result = a / b;
	cout << "Div= " << result;

	double mag=~a;
	cout << "Magnitude of a=" << mag << endl;
	mag = ~b;
	cout << "Magnitude of b=" << mag << endl;
	
	if (a != b) cout << "Not Equal" << endl;
	else cout << "Equal" << endl;
	
	
	return 0;
}