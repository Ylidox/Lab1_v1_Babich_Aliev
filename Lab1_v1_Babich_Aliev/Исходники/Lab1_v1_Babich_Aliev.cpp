#include <iostream>
#include <iomanip>
#include <compare>
#include "files.h"

int main()
{
    std::cout << "Hello World!\n";

    Mass m;
    cin >> m;

    //Velocity v = 10.0_xmps + 11.0_ymps + 3.2_zmps;
    Velocity v;
    cin >> v;

    Impulse p = m * v;
    
    //Mass m1 = p / v;
    std::cout << p;

    double (Mass:: * get_v)() = &Mass::get_v;
    std::cout << (m.*get_v)();
}
