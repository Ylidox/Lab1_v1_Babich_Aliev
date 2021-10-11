#include "Impulse.h"
#include "files.h"
Impulse::Impulse() {};

Impulse::Impulse(double a, double b, double c)
{
	this->setX(a);
	this->setY(b);
	this->setZ(c);
}

Impulse::Impulse(const Impulse& v)
{
	this->setX(v.getX());
	this->setY(v.getY());
	this->setZ(v.getZ());
}

Impulse Impulse::operator+(const Impulse& v) const
{
	return Impulse(
		x + v.getX(),
		y + v.getY(),
		z + v.getZ());
}

Impulse Impulse::operator-(const Impulse& v) const
{
	return Impulse(
		x - v.getX(),
		y - v.getY(),
		z - v.getZ());
}

Impulse& Impulse::operator=(const Impulse& v)
{
	this->setX(v.getX());
	this->setY(v.getY());
	this->setZ(v.getZ());

	return *this;
}

Impulse operator*(const Mass& m, const Velocity& v)
{
	return Impulse(m.get() * v.getX(), m.get() * v.getY(), m.get() * v.getZ());
}

Impulse operator*(const Velocity& v, const Mass& m)
{
	return Impulse(m.get() * v.getX(), m.get() * v.getY(), m.get() * v.getZ());
}

Impulse operator/(const Energy& e, const Velocity& v)
{
	return Impulse(e.get() / v.getX(),
		e.get() / v.getY(),
		e.get() / v.getZ());
}

ostream& operator<<(ostream& os, const Impulse& a)
{
	os << "x:" << a.getX() << "kgm/s" << endl;
	os << "y:" << a.getY() << "kgm/s" << endl;
	os << "z:" << a.getZ() << "kgm/s" << endl;
	return os;
}

istream& operator>>(istream& is, Impulse& a)
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

Impulse operator "" _xkgmps(long double a) {
	return Impulse(a, 0, 0);
}
Impulse operator "" _ykgmps(long double a) {
	return Impulse(0, a, 0);
}
Impulse operator "" _zkgmps(long double a) {
	return Impulse(0, 0, a);
}