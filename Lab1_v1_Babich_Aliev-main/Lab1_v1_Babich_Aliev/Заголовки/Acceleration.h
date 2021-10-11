#pragma once
#include <iostream>
#include <iomanip>
#include <compare> 
#include "Vector.h"
using namespace std;

class Acceleration : public Vector
{
public:
	Acceleration();
	Acceleration(double a, double b, double c);
	Acceleration(const Acceleration& v);

	~Acceleration() {};

	Acceleration operator+(const Acceleration& v) const;
	Acceleration operator-(const Acceleration& v) const;
	Acceleration operator/(double a) const;
	Acceleration& operator=(const Acceleration& v);
};

Acceleration operator "" _xmpss(long double a);
Acceleration operator "" _ympss(long double a);
Acceleration operator "" _zmpss(long double a);

ostream& operator<<(ostream& os, const Acceleration& a);
istream& operator>>(istream& is, Acceleration& a);