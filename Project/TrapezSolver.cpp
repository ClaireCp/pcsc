/*
 * TrapezSolver.cpp
 *
 *  Created on: November 25, 2018
 *      Author: Benjamin Schenk <benjamin.schenk@epfl.ch>
 */

#include "TrapezSolver.hpp"

double TrapezSolver::SolveIntegral() {
  double h = GetStepSize();
  double a = GetInitialArgument();
  double b = GetFinalArgument();
  // adding the contribution of the initial and the final argument to the integral
  double Integral = (h/2)*(GetFunctionValue(a)+GetFunctionValue(b));

  // loop over number of steps (point a and point b excluded)
  for (int i = 1; i < GetNumberOfSteps(); i++) {
    // calculation of the next point
    double x = a + i*h;
    // evaluate the function at x, multiply by the time step and add to the integral
    Integral += h*GetFunctionValue(x);
  }
  return Integral;
}