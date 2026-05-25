#include "polynomial/polynomial.h"

#include <iostream>

Polynomial f(double c2, double c1, double c0)
{
    return Polynomial{2, {c0, c1, c2}};
}

int main()
{
    Polynomial p{2, {0.0, 0.0, 1.0}};
    std::cout << "Before: " << p << '\n';
    p = f(3.0, 2.0, 1.0);
    std::cout << "After:  " << p << '\n';
}
