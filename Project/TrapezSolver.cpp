/*
 * TrapezSolver.cpp
 *
 *  Created on: Nov 25, 2018
 *      Author: beschenk
 */

#include <cassert>
#include <cmath>
#include <iostream>

#include "TrapezSolver.hpp"

TrapezSolver::TrapezSolver() {}

TrapezSolver::~TrapezSolver() {}

double TrapezSolver::SolveIntegral() {
  double h=GetStepSize();
  double a=GetInitialArgument();
  double b=GetFinalArgument();
  double Integral=(h/2)*(myFunction(a)+myFunction(b));
  for (int i=1; i<GetNumberOfSteps(); i++) {
    double x=a+i*h;
    Integral += h*myFunction(x);
  }
  return Integral;
}
