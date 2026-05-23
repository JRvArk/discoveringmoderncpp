#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iosfwd>
#include <vector>

class Polynomial
{
public:
    explicit Polynomial(int degree);
    Polynomial(int degree, std::vector<double> init_coefficients);
    ~Polynomial() = default;

    [[nodiscard]] int degree() const;
    [[nodiscard]] double coefficient(int power) const;

    friend std::ostream& operator<<(std::ostream& out, const Polynomial& poly);

private:
    std::vector<double> coefficients; // coefficients[i] is coefficient of x^i
};

#endif // POLYNOMIAL_H
