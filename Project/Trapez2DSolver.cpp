//
// Created by claire on 25.11.18.
//

#include "Trapez2DSolver.h"
#include "Abstract2DIntegralSolver.h"

Trapez2DSolver::Trapez2DSolver(int n_x, double x0, double xf, int n_y, double y0, double yf,
                               double (*my2DFunction)(double x, double y)) :
        Abstract2DIntegralSolver(n_x, x0, xf, n_y, y0, yf, my2DFunction) {}

double Trapez2DSolver::SolveIntegral() {
    double Integral = 0;
    double h_x = GetStepSize();
    double h_y = GetStepSize_y();
    double x0 = GetInitialArgument();
    double y0 = GetInitialArgument_y();


    // Loop over x
    for (int i = 0; i < GetNumberOfSteps(); i++) {
        double x1 = x0+i*h_x;
        double x2 = x0+(i+1)*h_x;
        // Loop over y
        for (int j = 0; j < GetNumberOfSteps_y(); j++) {
            double y1 = y0+j*h_y;
            double y2 = y0+(j+1)*h_y;
            Integral += h_x*h_y*(my2DFunction_xy(x1,y1)+my2DFunction_xy(x1,y2)+my2DFunction_xy(x2,y1)+my2DFunction_xy(x2,y2))/4;

        }

    }
    return Integral;
}
