#pragma once
#include <iostream>
#include <iomanip>
#include <compare> 
#include "Vector.h"
using namespace std;

class Force : public Vector
{
public:
	Force();
	Force(double a, double b, double c);
	Force(const Force& v);

	~Force() {};

	Force operator+(const Force& v) const;
	Force operator-(const Force& v) const;
	Force& operator=(const Force& v);
};

Force operator "" _xN(long double a);
Force operator "" _yN(long double a);
Force operator "" _zN(long double a);

ostream& operator<<(ostream& os, const Force& a);
istream& operator>>(istream& is, Force& a);