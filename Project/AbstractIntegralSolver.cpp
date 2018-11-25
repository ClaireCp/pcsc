/*
 * AbstractIntegralSolver.cpp
 *
 *  Created on: Nov 25, 2018
 *      Author: beschenk
 */

#include "AbstractIntegralSolver.hpp"

AbstractIntegralSolver::AbstractIntegralSolver()
    : numberOfSteps(), initialArgument(), finalArgument(), function(0) {}

AbstractIntegralSolver::~AbstractIntegralSolver() {}

void AbstractIntegralSolver::SetNumberOfSteps(const double n) { numberOfSteps = n; }

void AbstractIntegralSolver::SetInterval(const double x0, const double xf) {
  initialArgument = x0;
  finalArgument = xf;
}

void AbstractIntegralSolver::SetFunction(double (*f)(double x)) {
  function = f;
}

double AbstractIntegralSolver::myFunction(double x) const {
  return function(x);
}

