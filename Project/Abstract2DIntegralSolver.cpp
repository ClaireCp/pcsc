//
// Created by claire on 25.11.18.
//

/**

#include <iostream>
#include "AbstractIntegralSolver.hpp"
#include "Abstract2DIntegralSolver.h"
#include "Tools.h"

Abstract2DIntegralSolver::Abstract2DIntegralSolver(int n_x, double x0, double xf,
                                                   int n_y, double y0, double yf,
                                                   double (*my2DFunction_xy)(double x, double y)): AbstractIntegralSolver(n_x, x0, xf) {
    checkNumberOfSteps(n_y);
    numberOfSteps_y = n_y;
    checkInterval(&y0, &yf);
    initialArgument_y = y0;
    finalArgument_y = yf;
    SetFunction_xy(my2DFunction_xy);
}

Abstract2DIntegralSolver::~Abstract2DIntegralSolver() {}

void Abstract2DIntegralSolver::SetNumberOfSteps_y(const double n_y) {
    checkNumberOfSteps(n_y);
    numberOfSteps_y = n_y;
};

void Abstract2DIntegralSolver::SetInterval_y(double y0, double yf) {
    checkInterval(&y0, &yf);
    initialArgument_y = y0;
    finalArgument_y = yf;
}

void Abstract2DIntegralSolver::SetFunction_xy(double (*f_xy)(double x, double y)) {
    function_xy = f_xy;
}

double Abstract2DIntegralSolver::my2DFunction_xy(double x, double y) const {
    return function_xy(x, y);
}

 */