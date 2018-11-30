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

// TODO: transformer ça en fonction lambda -> fonction ne doit pas être virtuelle





