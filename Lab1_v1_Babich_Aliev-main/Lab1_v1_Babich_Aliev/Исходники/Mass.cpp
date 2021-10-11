#include "Mass.h"
#include "files.h"
//#include "input.h"

Mass::Mass() : value(0) {}

Mass::Mass(double value)
{
    this->value = value;
    if (value <= 0) this->value = 0;
}

Mass::Mass(const Mass& a) : value(a.value) {}

double Mass::get() const
{
    return value;
}

double Mass::get_v() {
    return value;
}

void Mass::set(double value)
{
    this->value = value;
}

Mass Mass::operator+(const Mass& a) const
{

    return Mass(value + a.value);
}

Mass Mass::operator-(double a) const
{
    if (value - a > 0) return Mass(value - a);
    else return Mass(0);
}

Mass Mass::operator/(double a) const
{
    if (a == 0) a = 1;
    return  Mass(value / a);
}

Mass& Mass::operator=(const Mass& a)
{
    this->set(a.get());
    return *this;
}

Mass operator/(const Impulse& p, const Velocity& v) {
    return Mass(p.abs() / v.abs());
}

Mass operator/(const Force& f, const Acceleration& a) {
    return Mass(f.abs() / a.abs());
}

ostream& operator<<(ostream& os, const Mass& a)
{
    os << a.get() << "kg" << endl;
    return os;
}

istream& operator>>(istream& is, Mass& a)
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

Mass operator "" _kg(long double a) {
    return Mass(a);
}

bool Mass::operator==(const Mass& mass) const noexcept
{
    return this->value == mass.value;
}


//std::partial_ordering Mass::operator<=>(const Mass& mass) const noexcept
//{
//    return value <=> mass.get();
//}