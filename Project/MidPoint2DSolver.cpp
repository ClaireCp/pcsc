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
            double x1 = x0 + i*h_x;
            double x2 = x0 +(i + 1)*h_x;
            double c_x = (x1 + x2)/2;
            double y1 = y0 + i*h_y;
            double y2 = y0 + (i + 1)*h_y;
            double c_y = (y1 + y2)/2;
            // TODO: look at how to implement the solveIntegral for functions with 2 variables
            Integral += h_x*myFunction(c_x);
        }
    }
    return Integral;
}