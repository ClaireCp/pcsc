/*
 * TrapezSolver.hpp
 *
 *  Created on: Nov 25, 2018
 *      Author: beschenk
 */

/**
#ifndef TRAPEZSOLVER_HPP
#define TRAPEZSOLVER_HPP

#include "AbstractIntegralSolver.hpp"

class TrapezSolver : public AbstractIntegralSolver {
public:
  TrapezSolver();
  virtual ~TrapezSolver();

  double SolveIntegral();
};

#endif /* TRAPEZSOLVER_HPP */
