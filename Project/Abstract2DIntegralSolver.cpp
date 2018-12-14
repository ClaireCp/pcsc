//
// Created by claire on 25.11.18.
//

#include <iostream>
#include "AbstractIntegralSolver.hpp"
#include "Abstract2DIntegralSolver.hpp"
#include "Tools.hpp"

Abstract2DIntegralSolver::Abstract2DIntegralSolver(int n_x, double x0, double xf,
                                                   int n_y, double y0, double yf,
                                                   t f): AbstractIntegralSolver(n_x, x0, xf, f) {
    checkNumberOfSteps(n_y);
    numberOfSteps_y = n_y;
    checkInterval(&y0, &yf);
    initialArgument_y = y0;
    finalArgument_y = yf;
}

