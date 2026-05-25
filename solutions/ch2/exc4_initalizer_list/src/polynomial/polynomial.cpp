#include "polynomial.h"

#include <algorithm>
#include <cmath>
#include <initializer_list>
#include <iostream>
#include <iterator>
#include <ostream>
#include <stdexcept>

Polynomial::Polynomial(int degree)
{
    if (degree < 0)
    {
        throw std::invalid_argument("Degree must be non-negative");
    }
    coefficients.assign(degree + 1, 0.0);
}

Polynomial::Polynomial(int degree, std::vector<double> init_coefficients)
    : coefficients(std::move(init_coefficients))
{
    if (degree < 0)
    {
        throw std::invalid_argument("Degree must be non-negative");
    }
    if (static_cast<int>(coefficients.size()) != degree + 1)
    {
        throw std::invalid_argument("Number of coefficients must be degree + 1");
    }
}

Polynomial::Polynomial(std::initializer_list<double> il)
    : coefficients(std::rbegin(il), std::rend(il))
{
}

Polynomial& Polynomial::operator=(std::initializer_list<double> il)
{
    coefficients.assign(std::rbegin(il), std::rend(il));
    return *this;
}

Polynomial& Polynomial::operator=(Polynomial&& other) noexcept
{
    std::cout << "Move assignment called\n";
    coefficients = std::move(other.coefficients);
    return *this;
}

int Polynomial::degree() const
{
    return static_cast<int>(coefficients.size()) - 1;
}

double Polynomial::coefficient(int power) const
{
    return coefficients.at(power);
}

std::ostream& operator<<(std::ostream& out, const Polynomial& poly)
{
    bool written = false;
    for (int idx = poly.degree(); idx >= 0; --idx)
    {
        double coeff = poly.coefficients.at(idx);
        if (coeff == 0.0)
        {
            continue;
        }

        if (written)
        {
            out << (coeff < 0.0 ? " - " : " + ");
        }
        else if (coeff < 0.0)
        {
            out << "-";
        }

        double abs_coeff = std::abs(coeff);
        if (idx == 0 || abs_coeff != 1.0)
        {
            out << abs_coeff;
        }
        if (idx > 0)
        {
            out << "x";
            if (idx > 1)
            {
                out << "^" << idx;
            }
        }
        written = true;
    }
    if (!written)
    {
        out << "0";
    }
    return out;
}
