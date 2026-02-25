#ifndef APPROX_HPP
#define APPROX_HPP
#include "derivative.hpp"
#include "math_funcs.hpp"
#include <cmath>

namespace numerics {

    template<typename Func>
    double linear_approx(Func f, double x) {
        const double a = 0.0;
        return (f(a) + (derivative(f, a)*(x - a)));
    }


    template<typename Func>
    double quadratic_approx(Func f, double x) {
        const double a = 0.0;
        return (f(a) + (derivative(f, a)*(x - a)) + (second_derivative(f, a)/factorial(2))*(std::pow(x - a, 2)));
    }

    template<typename Func>
    double taylor_approx(Func f, double x) {
        return 0.0;
    }

}

#endif