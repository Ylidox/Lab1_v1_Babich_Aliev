#include "Velocity.h"
#include "files.h"
Velocity::Velocity() {}

Velocity::Velocity(double a, double b, double c)
{
	this->setX(a);
	this->setY(b);
	this->setZ(c);
}

Velocity::Velocity(const Velocity& v)
{
	this->setX(v.getX());
	this->setY(v.getY());
	this->setZ(v.getZ());
}

Velocity Velocity::operator+(const Velocity& v) const {
	return Velocity(
		x + v.getX(),
		y + v.getY(),
		z + v.getZ());
}

Velocity Velocity::operator-(const Velocity& v) const{
	return Velocity(
		x - v.getX(),
		y - v.getY(),
		z - v.getZ());
}

Velocity Velocity::operator*(const Velocity& v) const {
	double x2 = v.getX();
	double y2 = v.getY();
	double z2 = v.getZ();

	double x1 = y * z2 - y2 * z;
	double y1 = z * x2 - z2 * x;
	double z1 = x * y2 - x2 * y;

	return Velocity(x1, y1, z1);
}

Velocity Velocity::operator/(double a) const {
	if (a == 0) return Velocity(0, 0, 0);
	return Velocity(this->getX() / a, this->getY() / a, this->getZ() / a);
}

Velocity& Velocity::operator=(const Velocity& v)
{
	this->setX(v.getX());
	this->setY(v.getY());
	this->setZ(v.getZ());

	return *this;
}

Velocity operator/(const Impulse& p, const Mass& m) {
	return Velocity(p.getX() / m.get(),
		p.getY() / m.get(),
		p.getZ() / m.get());
}

Velocity operator/(const Energy& e, const Impulse& p) {
	return Velocity(e.get() / p.getX(),
		e.get() / p.getY(),
		e.get() / p.getZ());
}

ostream& operator<<(ostream& os, const Velocity& a)
{
	os << "x:" << a.getX() << "m/s" << endl;
	os << "y:" << a.getY() << "m/s" << endl;
	os << "z:" << a.getZ() << "m/s" << endl;
	return os;
}

istream& operator>>(istream& is, Velocity& a)
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

Velocity operator "" _xmps(long double a) {
	return Velocity(a, 0, 0);
}
Velocity operator "" _ymps(long double a) {
	return Velocity(0, a, 0);
}
Velocity operator "" _zmps(long double a) {
	return Velocity(0, 0, a);
}

