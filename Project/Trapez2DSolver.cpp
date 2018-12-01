//
// Created by claire on 25.11.18.
//

#include "Trapez2DSolver.h"
#include "Abstract2DIntegralSolver.h"

double Trapez2DSolver::SolveIntegral() {
    double Integral = 0;
    double h_x = GetStepSize();
    double h_y = GetStepSize_y();
    double x0 = GetInitialArgument();
    double y0 = GetInitialArgument_y();

    // Loop over x
    for (int i = 0; i < GetNumberOfSteps(); i++) {

        // Loop over y
        for (int j = 0; j < GetNumberOfSteps_y(); j++) {
            double x1 = x0 + i * h_x;
            double x2 = x0 + (i + 1) * h_x;
            double c_x = (x1 + x2) / 2;
            double y1 = y0 + i * h_y;
            double y2 = y0 + (i + 1) * h_y;
            double c_y = (y1 + y2) / 2;

        }

    }
    return Integral;
}
