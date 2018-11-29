/*
 * MidPointSolver.hpp
 *
 *  Created on: Nov 25, 2018
 *      Author: beschenk
 */

#ifndef MIDPOINTSOLVER_HPP
#define MIDPOINTSOLVER_HPP

#include "AbstractIntegralSolver.hpp"

class MidPointSolver : public AbstractIntegralSolver {
public:
  MidPointSolver();
  MidPointSolver(int numberOfSteps, double initialArgument, double finalArgument);
  MidPointSolver(int numberOfSteps, double initialArgument, double finalArgument, double (*my1DFunction)(double x));
  virtual ~MidPointSolver();

  double SolveIntegral();
};

#endif /* MIDPOINTSOLVER_HPP */
