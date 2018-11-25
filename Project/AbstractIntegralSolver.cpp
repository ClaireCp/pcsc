/*
 * AbstractIntegralSolver.cpp
 *
 *  Created on: Nov 25, 2018
 *      Author: beschenk
 */

#include <iostream>
#include "AbstractIntegralSolver.hpp"

AbstractIntegralSolver::AbstractIntegralSolver()
    : numberOfSteps(), initialArgument(), finalArgument(), function(0) {}

// TODO: create methods to check if parameters are valid to limit code reuse
AbstractIntegralSolver::AbstractIntegralSolver(int n, double x0, double xf) {
  std::cout << "Welcome to overloaded constructor" << std::endl;
  std::flush(std::cout);
  if (n < 0) {
    std::cout << "The number of iteration has to be strictly superior to 0." << std::endl;
    exit(1);
  }
  numberOfSteps = n;
  if (x0 < xf) {
    initialArgument = x0;
    finalArgument = xf;
  } else {
    initialArgument = xf;
    finalArgument = x0;
  }
}

AbstractIntegralSolver::~AbstractIntegralSolver() {}

void AbstractIntegralSolver::SetNumberOfSteps(const double n) {
  if (n < 0) {
    std::cout << "The number of iteration has to be stricly superior to 0." << std::endl;
    exit(1);
  }
  numberOfSteps = n;
}

void AbstractIntegralSolver::SetInterval(const double x0, const double xf) {
  if (x0 < xf) {
    initialArgument = x0;
    finalArgument = xf;
  } else {
    initialArgument = xf;
    finalArgument = x0;
  }
}

void AbstractIntegralSolver::SetFunction(double (*f)(double x)) {
  function = f;
}

double AbstractIntegralSolver::myFunction(double x) const {
  return function(x);
}



