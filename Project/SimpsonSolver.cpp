/*
 * SimpsonSolver.cpp
 *
 *  Created on: Nov 25, 2018
 *      Author: beschenk
 */


#include <cassert>
#include <cmath>
#include <iostream>

#include "SimpsonSolver.hpp"

double SimpsonSolver::SolveIntegral() {
    double Integral=0;
    double h = GetStepSize();
    double a = GetInitialArgument();

    for (int i = 0; i < GetNumberOfSteps(); i++) {
        double x1=a+i*h;
        double x2=a+(i+1)*h;
        double c=(x1+x2)/2;
        Integral += (h/6)*(myFunction(x1)+4*myFunction(c)+myFunction(x2));
    }
    return Integral;
}
