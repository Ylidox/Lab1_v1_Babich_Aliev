#pragma once
#include <iostream>
//#include <iomanip>
#include <compare>

//#include "files.h"
using namespace std;

class Energy
{
private:
	double value = 0;
public:
	Energy();
	Energy(double value);
	Energy(const Energy& a);
	~Energy() {};

	double get() const;
	void set(double value);
	Energy operator+(const Energy& e) const;
	Energy operator-(const Energy& e) const;
	Energy operator*(double a) const;
	Energy operator/(double a) const;

	Energy& operator=(const Energy& a);

	//std::partial_ordering operator<=>(const Energy& e) const noexcept;
};

Energy operator "" _J(long double a);

ostream& operator<<(ostream& os, const Energy& a);
istream& operator>>(istream& is, Energy& a);