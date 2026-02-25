#ifndef MATH_HPP
#define MATH_HPP


    int factorial(int x) {
        int total=1;

        for (int i=x;i>0;--i) {
            total*=i;
        }
        return total;
    }





#endif