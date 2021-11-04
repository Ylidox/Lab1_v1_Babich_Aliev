#pragma once
#include "files.h"

Impulse operator*(const Mass& m, const Velocity& v);
Impulse operator*(const Velocity& v, const Mass& m);
Impulse operator/(const Energy& e, const Velocity& v);

Mass operator/(const Impulse& p, const Velocity& v);
Mass operator/(const Force& f, const Acceleration& a);

Energy operator*(const Impulse& p, const Velocity& v);
Energy operator*(const Velocity& v, const Impulse& p);
Energy operator*(const Force& f, double a);
Energy operator*(double a, const Force& f);
Energy operator*(const Mass& m, double a);

Force operator*(const Mass& m, const Acceleration& a);
Force operator*(const Acceleration& a, const Mass& m);

Velocity operator/(const Impulse& p, const Mass& m);
Velocity operator/(const Energy& e, const Impulse& p);
