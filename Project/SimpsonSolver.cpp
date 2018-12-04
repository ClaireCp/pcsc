/*
 * SimpsonSolver.cpp
 *
 *  Created on: November 25, 2018
 *      Author: Benjamin Schenk <benjamin.schenk@epfl.ch>
 */


#include "SimpsonSolver.hpp"

double SimpsonSolver::SolveIntegral() {
    double Integral=0;
    double h = GetStepSize();
    double a = GetInitialArgument();

    // Loop over the number of steps
    for (int i = 0; i < GetNumberOfSteps(); i++) {
        // argument where the sub interval begins
        double x1=a+i*h;
        // argument where the sub interval ends
        double x2=a+(i+1)*h;
        // center of the sub interval
        double c=(x1+x2)/2;
        // Evaluation of the function and weighted adding to the Integral
        Integral += (h/6)*(GetFunctionValue(x1)+4*GetFunctionValue(c)+GetFunctionValue(x2));
    }
    return Integral;
}
