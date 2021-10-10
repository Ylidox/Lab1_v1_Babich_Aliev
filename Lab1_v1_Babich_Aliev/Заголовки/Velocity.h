#pragma once
#include <iostream>
#include <iomanip>
#include <compare>
#include "Vector.h"

using namespace std;

class Velocity : public Vector
{
public:
	Velocity();
	Velocity(double a, double b, double c);
	Velocity(const Velocity& v);

	~Velocity() {};

	Velocity operator+(const Velocity& v);
	Velocity operator-(const Velocity& v);
	Velocity operator*(const Velocity& v);
	Velocity operator/(double a);
	Velocity& operator=(const Velocity& v);
};

Velocity operator "" _xmps(long double a);
Velocity operator "" _ymps(long double a);
Velocity operator "" _zmps(long double a);

ostream& operator<<(ostream& os, const Velocity& a);
istream& operator>>(istream& is, Velocity& a);