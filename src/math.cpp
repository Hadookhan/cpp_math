#include <iostream>
#include "../include/derivative.hpp"
#include "../include/approximation.hpp"
#include <cmath>

using namespace numerics;
using namespace std;

int main() {

    auto f = [](double x) {
        return pow(sin(x),2);
    };

    cout << derivative(f, 0) << "\n";
    cout << second_derivative(f, 0) << "\n";

    cout << linear_approx(f, 0.1) << "\n";
    cout << quadratic_approx(f, 0.1) << "\n";

    return 0;
}