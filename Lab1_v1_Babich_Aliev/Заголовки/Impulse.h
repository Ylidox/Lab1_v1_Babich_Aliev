#pragma once
#include <iostream>
#include <iomanip>
#include "Vector.h"
#include "Mass.h"
#include "Velocity.h"
#include "Energy.h"
//#include "files.h"
using namespace std;

class Impulse : public Vector
{
public:
	Impulse();
	Impulse(double a, double b, double c);
	Impulse(const Impulse& v);

	~Impulse() {};	

	Impulse operator+(const Impulse& v);
	Impulse operator-(const Impulse& v);
	Impulse& operator=(const Impulse& v);
};

Impulse operator "" _xkgmps(long double a);
Impulse operator "" _ykgmps(long double a);
Impulse operator "" _zkgmps(long double a);

ostream& operator<<(ostream& os, const Impulse& a);
istream& operator>>(istream& is, Impulse& a);

Impulse operator*(const Mass& m, const Velocity& v);
Impulse operator*(const Velocity& v, const Mass& m);
Impulse operator/(const Energy& e, const Velocity& v);
