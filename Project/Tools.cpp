/*
 * Tools.cpp
 *
 * Created on: December 1, 2018
 * 	   Author: Claire Capelo <claire.capelo@epfl.ch>
 */

#include <cstdlib>
#include <iostream>

#include "Tools.hpp"

void checkNumberOfSteps(int n) {
    if (n < 0) {
        std::cerr << "The number of iteration has to be strictly superior to 0." << std::endl;
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
