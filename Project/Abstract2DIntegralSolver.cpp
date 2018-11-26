//
// Created by claire on 25.11.18.
//

#include <iostream>
#include "AbstractIntegralSolver.hpp"
#include "Abstract2DIntegralSolver.h"

Abstract2DIntegralSolver::Abstract2DIntegralSolver(int n_x, double x0, double xf,
                                                   int n_y, double y0, double yf,
                                                   double (*my2DFunction_xy)(double x, double y)): AbstractIntegralSolver(n_x, x0, xf) {
    if (n_y < 0) {
        std::cout << "The number of iteration has to be strictly superior to 0." << std::endl;
        exit(1);
    }
    numberOfSteps_y = n_y;
    if (y0 < yf) {
        initialArgument_y = y0;
        finalArgument_y = yf;
    } else {
        initialArgument_y = yf;
        finalArgument_y = y0;
    }
    SetFunction_xy(my2DFunction_xy);
}

Abstract2DIntegralSolver::~Abstract2DIntegralSolver() {}

void Abstract2DIntegralSolver::SetNumberOfSteps_y(const double n_y) {
    if (n_y < 0) {
        std::cout << "The number of iteration has to be stricly superior to 0." << std::endl;
        exit(1);
    }
    numberOfSteps_y = n_y;
};

void Abstract2DIntegralSolver::SetInterval_y(const double y0, const double yf) {
    if (y0 < yf) {
        initialArgument_y = y0;
        finalArgument_y = yf;
    } else {
        initialArgument_y = yf;
        finalArgument_y = y0;
    }
}
void Abstract2DIntegralSolver::SetFunction_xy(double (*f_xy)(double x, double y)) {
    function_xy = f_xy;
}

double Abstract2DIntegralSolver::my2DFunction_xy(double x, double y) const {
    return function_xy(x, y);
}
