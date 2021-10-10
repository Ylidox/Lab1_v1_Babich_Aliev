#include "Force.h"
#include "files.h"
 
Force::Force() {};

Force::Force(double a, double b, double c)
{
	this->setX(a);
	this->setY(b);
	this->setZ(c);
}

Force::Force(const Force& v)
{
	this->setX(v.getX());
	this->setY(v.getY());
	this->setZ(v.getZ());
}

Force Force::operator+(const Force& v)
{
	return Force(
		x + v.getX(),
		y + v.getY(),
		z + v.getZ());
}

Force Force::operator-(const Force& v)
{
	return Force(
		x - v.getX(),
		y - v.getY(),
		z - v.getZ());
}

Force& Force::operator=(const Force& v)
{
	this->setX(v.getX());
	this->setY(v.getY());
	this->setZ(v.getZ());

	return *this;
}

Force operator*(const Mass& m, const Acceleration& a) {
	return Force(a.getX() / m.get(),
		a.getY() / m.get(),
		a.getZ() / m.get());
}
Force operator*(const Acceleration& a, const Mass& m) {
	return Force(a.getX() / m.get(),
		a.getY() / m.get(),
		a.getZ() / m.get());
}

ostream& operator<<(ostream& os, const Force& a)
{
	os << "x:" << a.getX() << "N" << endl;
	os << "y:" << a.getY() << "N" << endl;
	os << "z:" << a.getZ() << "N" << endl;
	return os;
}

istream& operator>>(istream& is, Force& a)
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



Force operator "" _xN(long double a) {
	return Force(a, 0, 0);
}
Force operator "" _yN(long double a) {
	return Force(0, a, 0);
}
Force operator "" _zN(long double a) {
	return Force(0, 0, a);
}
