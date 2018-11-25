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
  virtual ~MidPointSolver();

  double SolveIntegral();
};

#endif /* MIDPOINTSOLVER_HPP */
