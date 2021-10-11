#pragma once

#include <iostream>
double input() {
    double a;
    while (!(std::cin >> a) || (std::cin.peek() != '\n'))
    {
        std::cin.clear();
        while (std::cin.get() != '\n');
        std::cout << "Error!" << std::endl;
    }
    return a;
}