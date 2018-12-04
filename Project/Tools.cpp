//
// Created by claire on 26.11.18.
//

#include <cstdlib>
#include <iostream>

#include "Tools.hpp"

void checkNumberOfSteps(int n) {
    if (n < 0) {
        std::cout << "The number of iteration has to be strictly superior to 0." << std::endl;
        exit(1);
    }
}

void checkInterval(double* x0, double* xf) {
    double tmp = 0;
    if (*xf < *x0) {
        tmp = *x0;
        *x0 = *xf;
        *xf = tmp;
    }
}
