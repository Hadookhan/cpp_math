#ifndef DERIVATIVE_HPP
#define DERIVATIVE_HPP

namespace numerics {
    // Central difference derivative
    template<typename Func>
    double derivative(Func f, double x) {
        double h = 1e-6; // numerical approximation (~0)
        return (f(x + h) - f(x - h)) / (2 * h);
    }

    // Second derivative
    template<typename Func>
    double second_derivative(Func f, double x) {
        double h = 1e-6;
        return (f(x + h) - 2*f(x) + f(x - h)) / (h*h);
    }
}

#endif