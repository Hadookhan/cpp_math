#include <iostream>
#include "../include/derivative.hpp"
#include "../include/approximation.hpp"
#include <cmath>

using namespace numerics;

int main() {

    auto f = [](double x) {
        return std::pow(std::sin(x),2);
    };

    std::cout << derivative(f, 0) << "\n";
    std::cout << second_derivative(f, 0) << "\n";

    std::cout << linear_approx(f, 0.1) << "\n";
    std::cout << quadratic_approx(f, 0.1) << "\n";

    return 0;
}