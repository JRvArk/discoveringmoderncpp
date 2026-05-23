#include "polynomial/polynomial.h"

#include <exception>
#include <iostream>

int main()
{
    try
    {
        // Zero polynomial of degree 2 (all coefficients default to 0)
        Polynomial poly_zero(2);
        std::cout << "zero degree-2 polynomial: " << poly_zero << '\n';

        // 3x^2 - 2x + 1  (coefficients ordered lowest to highest: [1, -2, 3])
        Polynomial poly_quad(2, {1.0, -2.0, 3.0});
        std::cout << "poly_quad = " << poly_quad << '\n';
        std::cout << "degree of poly_quad = " << poly_quad.degree() << '\n';
        std::cout << "poly_quad coefficient of x^2 = " << poly_quad.coefficient(2) << '\n';

        // x^3  (leading coefficient 1, others 0)
        Polynomial poly_cub(3, {0.0, 0.0, 0.0, 1.0});
        std::cout << "poly_cub = " << poly_cub << '\n';

        // -x + 5
        Polynomial poly_lin(1, {5.0, -1.0});
        std::cout << "poly_lin = " << poly_lin << '\n';
    }
    catch (const std::exception& exc)
    {
        std::cerr << "Error: " << exc.what() << '\n';
        return 1;
    }
}
