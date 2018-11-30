/*
 * AbstractIntegralSolver.cpp
 *
 *  Created on: Nov 25, 2018
 *      Author: beschenk
 */

#include <iostream>
#include "AbstractIntegralSolver.hpp"
#include "Tools.h"

//template <typename t>
//AbstractIntegralSolver<t>::AbstractIntegralSolver()
//    : numberOfSteps(), initialArgument(), finalArgument(), function() {}

// TODO: create methods to check if parameters are valid to limit code reuse
template <typename t>
AbstractIntegralSolver<t>::AbstractIntegralSolver(int n, double x0, double xf, t f) {
  checkNumberOfSteps(n);
  numberOfSteps = n;
  checkInterval(&x0, &xf);
  initialArgument = x0;
  finalArgument = xf;
  SetFunction(f);
}

//AbstractIntegralSolver::~AbstractIntegralSolver() {}



