#include "Vector.h"
#include <math.h>
#include <iostream>

using namespace std;

Vector::Vector()
{
	x = 0;
	y = 0;
	z = 0;
}

Vector::Vector(double a, double b, double c)
{
	x = a;
	y = b;
	z = c;
}

Vector::Vector(const Vector& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
}

double Vector::getX() const
{
	return x;
}

double Vector::getY() const
{
	return y;
}

double Vector::getZ() const
{
	return z;
}

void Vector::setX(double x)
{
	this->x = x;
}

void Vector::setY(double y)
{
	this->y = y;
}

void Vector::setZ(double z)
{
	this->z = z;
}

double Vector::abs() const
{
	return sqrt(x * x + y * y + z * z);
}

//std::partial_ordering Vector::operator<=>(const Vector& v) const noexcept
//{
//    return this.abs() <=> v.abs();
//}