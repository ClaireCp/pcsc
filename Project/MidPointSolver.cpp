/*
 * MidPointSolver.cpp
 *
 *  Created on: November 25, 2018
 *      Author: Benjamin Schenk <benjamin.schenk@epfl.ch>
 */


#include "MidPointSolver.hpp"


double MidPointSolver::SolveIntegral() {

  double Integral = 0;
  double h = GetStepSize();
  double a = GetInitialArgument();

  // Loop over the number of steps
  for (int i = 0; i < GetNumberOfSteps(); i++) {
    // Defining the mid point of the sub interval
    double c = a + (i+0.5)*h;
    // Evaluate the Function and multiply by the step size and adding to the integral
    Integral += h*GetFunctionValue(c);
  }
  return Integral;
}
