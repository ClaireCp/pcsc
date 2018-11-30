//
// Created by claire on 25.11.18.
//

#include "MidPoint2DSolver.h"

MidPoint2DSolver::MidPoint2DSolver(int n_x, double x0, double xf,
                       int n_y, double y0, double yf,
                       double (*my2DFunction)(double x, double y)) :
                       Abstract2DIntegralSolver(n_x, x0, xf, n_y, y0, yf, my2DFunction) {}

// TODO: why do you need to make parameters private? Wouldn't it be better to simply let them public
// TODO: (cont) so that they can be accessed without getters?
double MidPoint2DSolver::SolveIntegral() {
    double Integral = 0;
    double h_x = GetStepSize();
    double h_y = GetStepSize_y();
    double x0 = GetInitialArgument();
    double y0 = GetInitialArgument_y();

    // Loop over x
    for (int i = 0; i < GetNumberOfSteps(); i++) {

        // Loop over y
        for (int j = 0; j < GetNumberOfSteps_y(); j++) {
            double x = x0 + h_x/2 + i*h_x;
            double y = y0 + h_y/2 + j*h_y;
            // TODO: look at how to implement the solveIntegral for functions with 2 variables
            // OK
            Integral += h_x*h_y*my2DFunction_xy(x,y);
        }
    }
    return Integral;
}