#include <iostream>
#include "../include/derivative.hpp"

using namespace numerics;

int main() {

    auto f = [](double x) {
        return x * x * x;
    };

    std::cout << derivative(f, 2.0) << "\n";
    std::cout << second_derivative(f, 2.0) << "\n";

    return 0;
}