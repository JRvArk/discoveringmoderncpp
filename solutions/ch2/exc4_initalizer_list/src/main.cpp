#include "polynomial/polynomial.h"

#include <iostream>

int main()
{
    Polynomial p{3.0, 2.0, 1.0}; // 3x^2 + 2x + 1
    std::cout << "Constructed: " << p << '\n';

    p = {5.0, 0.0, -1.0, 2.0}; // 5x^3 - x + 2
    std::cout << "Assigned:    " << p << '\n';
}
