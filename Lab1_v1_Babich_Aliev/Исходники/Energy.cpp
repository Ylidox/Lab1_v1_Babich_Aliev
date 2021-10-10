#include "Energy.h"
#include "files.h"
#include <iostream>
Energy::Energy() : value(0) {};

Energy::Energy(double value)
{
    if (value < 0) value *= -1;
    this->value = value;
}

Energy::Energy(const Energy& a) : value(a.value) {}

double Energy::get() const
{
    return value;
}

void Energy::set(double value)
{
    this->value = value;
}

Energy Energy::operator+(const Energy& e) const
{
    return Energy(value + e.value);
}

Energy Energy::operator-(const Energy& e) const
{
    return Energy(value - e.value);
}

Energy Energy::operator*(const double e) const
{
    return Energy(value * e);
}

Energy Energy::operator/(double e) const
{
    if (e == 0) e = 1;
    return Energy(value / e);
}


Energy operator*(const Impulse& p, const Velocity& v) {
    return Energy(p.abs() * v.abs());
}

Energy operator*(const Velocity& v, const Impulse& p) {
    return Energy(p.abs() * v.abs());
}

Energy operator*(const Force& f, double a) {
    return Energy(f.abs() * a);
}
Energy operator*(double a, const Force& f) {
    return Energy(f.abs() * a);
}

Energy operator*(const Mass& m, double a) {
    return Energy(m.get() * a);
}


ostream& operator<<(ostream& os, const Energy& a)
{
    os << "x:" << a.get() << "J" << endl;
    return os;
}

istream& operator>>(istream& is, Energy& a)
{
    double n;
    while (!(cin >> n) || (cin.peek() != '\n'))
    {
        cin.clear();
        while (cin.get() != '\n');
        cout << "Error!" << endl;
    }
    a.set(n);
    return is;
}

Energy operator "" _J(long double a) {
    return Energy(a);
}

//std::partial_ordering Energy::operator<=>(const Energy& e) const noexcept
//{
//    return value <=> e.get();
//}