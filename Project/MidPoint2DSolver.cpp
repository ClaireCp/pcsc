/*
 * MidPointSolver.cpp
 *
 *  Created on: November 25, 2018
 *      Author: Claire Capelo <claire.capelo@epfl.ch>
 */

#include "MidPoint2DSolver.hpp"

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
            // calculate the mid point of the x sub interval
            double c_x = x0 + (i+0.5)*h_x;
            // calculate the mid point of the y sub interval
            double c_y = y0 + (j+0.5)*h_y;
            // evaluate the function at the mid point, multiply by the two step sites and adding to the integral
            Integral += h_x*h_y*GetFunctionValue(c_x, c_y);
        }
    }
    return Integral;
}
