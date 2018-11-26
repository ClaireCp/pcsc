/*
 * AbstractIntegralSolver.cpp
 *
 *  Created on: Nov 25, 2018
 *      Author: beschenk
 */

#include <iostream>
#include "AbstractIntegralSolver.hpp"
#include "Tools.h"

AbstractIntegralSolver::AbstractIntegralSolver()
    : numberOfSteps(), initialArgument(), finalArgument(), function(0) {}

// TODO: create methods to check if parameters are valid to limit code reuse
AbstractIntegralSolver::AbstractIntegralSolver(int n, double x0, double xf) {
  checkNumberOfSteps(n);
  numberOfSteps = n;
  checkInterval(&x0, &xf);
  initialArgument = x0;
  finalArgument = xf;
}

AbstractIntegralSolver::AbstractIntegralSolver(int n, double x0, double xf,
        double (*my1DFunction)(double x)): AbstractIntegralSolver(n, x0, xf) {
  std::cout << "Welcome to overloaded constructor taking parameters" << std::endl;
  std::flush(std::cout);
  SetFunction(my1DFunction);
}

AbstractIntegralSolver::~AbstractIntegralSolver() {}

void AbstractIntegralSolver::SetNumberOfSteps(const double n) {
  checkNumberOfSteps(n);
  numberOfSteps = n;
}

void AbstractIntegralSolver::SetInterval(double x0, double xf) {
  checkInterval(&x0, &xf);
  initialArgument = x0;
  finalArgument = xf;
}

void AbstractIntegralSolver::SetFunction(double (*f)(double x)) {
  function = f;
}

double AbstractIntegralSolver::myFunction(double x) const {
  return function(x);
}



