#include "rational.h"

#include <numeric>
#include <ostream>
#include <stdexcept>

Rational::Rational(int numerator, int denominator) : numerator{numerator}, denominator{denominator}
{
    if (denominator == 0)
    {
        throw std::invalid_argument("denominator cannot be zero");
    }
    normalize();
}

Rational::Rational(int numerator) : numerator{numerator}, denominator{1} {}

void Rational::normalize()
{
    if (denominator < 0)
    {
        numerator   = -numerator;
        denominator = -denominator;
    }
    int divisor = std::gcd(std::abs(numerator), denominator);
    numerator /= divisor;
    denominator /= divisor;
}

Rational& Rational::operator+=(const Rational& rhs)
{
    numerator   = (numerator * rhs.denominator) + (rhs.numerator * denominator);
    denominator = denominator * rhs.denominator;
    normalize();
    return *this;
}

Rational& Rational::operator-=(const Rational& rhs)
{
    numerator   = (numerator * rhs.denominator) - (rhs.numerator * denominator);
    denominator = denominator * rhs.denominator;
    normalize();
    return *this;
}

Rational& Rational::operator*=(const Rational& rhs)
{
    numerator *= rhs.numerator;
    denominator *= rhs.denominator;
    normalize();
    return *this;
}

Rational& Rational::operator/=(const Rational& rhs)
{
    if (rhs.numerator == 0)
    {
        throw std::invalid_argument("division by zero");
    }
    numerator *= rhs.denominator;
    denominator *= rhs.numerator;
    normalize();
    return *this;
}

Rational operator+(Rational lhs, const Rational& rhs)
{
    return lhs += rhs;
}
Rational operator-(Rational lhs, const Rational& rhs)
{
    return lhs -= rhs;
}
Rational operator*(Rational lhs, const Rational& rhs)
{
    return lhs *= rhs;
}
Rational operator/(Rational lhs, const Rational& rhs)
{
    return lhs /= rhs;
}

std::ostream& operator<<(std::ostream& out, const Rational& rat)
{
    out << rat.get_numerator();
    if (rat.get_denominator() != 1)
    {
        out << '/' << rat.get_denominator();
    }
    return out;
}
