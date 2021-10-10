#pragma once
#include <iostream>
#include <iomanip>
#include <compare>


//#include "Impulse.h"
//#include "Velocity.h"
//#include "Force.h"
//#include "Acceleration.h"

using namespace std;

class Mass
{
private:
    double value = 0;
public:
    Mass();
    Mass(double value);
    Mass(const Mass& a);
    ~Mass() {}

    double get() const;
    double get_v();
    void set(double value);

    Mass operator+(const Mass& a) const;
    Mass operator-(double a) const;
    Mass operator/(double a) const;
    Mass& operator=(const Mass& a);

    bool operator==(const Mass& mass) const noexcept;
    //std::partial_ordering operator<=>(const Mass& mass) const noexcept;
};

Mass operator "" _kg(long double a);

//Mass operator/(const Impulse& p, const Velocity& v);
//Mass operator/(const Force& f, const Acceleration& a);

ostream& operator<<(ostream& os, const Mass& a);
istream& operator>>(istream& is, Mass& a);