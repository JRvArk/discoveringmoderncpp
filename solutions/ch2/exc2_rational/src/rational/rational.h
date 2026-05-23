#ifndef RATIONAL_H_
#define RATIONAL_H_

#include <iosfwd>

class Rational
{
public:
    Rational(int numerator, int denominator);
    Rational(int numerator);

    Rational& operator+=(const Rational& rhs);
    Rational& operator-=(const Rational& rhs);
    Rational& operator*=(const Rational& rhs);
    Rational& operator/=(const Rational& rhs);

    [[nodiscard]] int get_numerator() const { return numerator; }
    [[nodiscard]] int get_denominator() const { return denominator; }

private:
    void normalize();

    int numerator;
    int denominator;
};

Rational operator+(Rational lhs, const Rational& rhs);
Rational operator-(Rational lhs, const Rational& rhs);
Rational operator*(Rational lhs, const Rational& rhs);
Rational operator/(Rational lhs, const Rational& rhs);

std::ostream& operator<<(std::ostream& out, const Rational& rat);

#endif // RATIONAL_H_
