#include "Acceleration.h"

Acceleration::Acceleration() {};

Acceleration::Acceleration(double a, double b, double c)
{
	this->setX(a);
	this->setY(b);
	this->setZ(c);
}

Acceleration::Acceleration(const Acceleration& v)
{
	this->setX(v.getX());
	this->setY(v.getY());
	this->setZ(v.getZ());
}

Acceleration Acceleration::operator+(const Acceleration& v)const
{
	return Acceleration(
		x + v.getX(),
		y + v.getY(),
		z + v.getZ());
}

Acceleration Acceleration::operator-(const Acceleration& v)const
{
	return Acceleration(
		x - v.getX(),
		y - v.getY(),
		z - v.getZ());
}

Acceleration Acceleration::operator/(double a) const
{
	if (a == 0) a = 0.1;
	return Acceleration(this->getX() / a, this->getY() / a, this->getZ() / a);
}

Acceleration& Acceleration::operator=(const Acceleration& v)
{
	this->setX(v.getX());
	this->setY(v.getY());
	this->setZ(v.getZ());

	return *this;
}

ostream& operator<<(ostream& os, const Acceleration& a)
{
	os << "x:" << a.getX() << "m/s2" << endl;
	os << "y:" << a.getY() << "m/s2" << endl;
	os << "z:" << a.getZ() << "m/s2" << endl;
	return os;
}
istream& operator>>(istream& is, Acceleration& a)
{
	double n[3]{ 0, 0, 0 };
	string s[3]{ "x: ", "y: ", "z: " };
	for (int i = 0; i < 3; i++) {
		cout << s[i];
		while (!(cin >> n[i]) || (cin.peek() != '\n'))
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "Error!" << endl;
		}
	}
	a.setX(n[0]);
	a.setY(n[1]);
	a.setZ(n[2]);
	return is;
}

Acceleration operator "" _xmpss(long double a) {
	return Acceleration(a, 0, 0);
}
Acceleration operator "" _ympss(long double a) {
	return Acceleration(0, a, 0);
}
Acceleration operator "" _zmpss(long double a) {
	return Acceleration(0, 0, a);
}