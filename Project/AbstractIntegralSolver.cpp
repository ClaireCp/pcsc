/*
 * AbstractIntegralSolver.cpp
 *
 *  Created on: Nov 25, 2018
 *      Author: Benjamin Schenk <benjamin.schenk@epfl.ch>
 */

 // TODO: Do we really need this file?
#include <iostream>
#include "AbstractIntegralSolver.hpp"
#include "Tools.hpp"

template <typename t>
AbstractIntegralSolver<t>::AbstractIntegralSolver(int n, double x0, double xf, t f) {
  checkNumberOfSteps(n);
  numberOfSteps = n;
  checkInterval(&x0, &xf);
  initialArgument = x0;
  finalArgument = xf;
  SetFunction(f);
}



