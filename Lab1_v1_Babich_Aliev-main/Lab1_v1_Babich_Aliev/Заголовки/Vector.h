#pragma once
#include <iostream>
class Vector
{
protected:
	double x, y, z;
public:
	Vector();
	Vector(double a, double b, double c);
	Vector(const Vector& v);
	double getX() const;
	double getY() const;
	double getZ() const;

	void setX(double x);
	void setY(double y);
	void setZ(double z);

	double abs() const;
	~Vector() {};
	//std::partial_ordering operator<=>(const Vector& v) const noexcept;
};

