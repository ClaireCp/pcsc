/*
 * SimpsonSolver.hpp
 *
 *  Created on: Nov 25, 2018
 *      Author: beschenk
 */
/**
#ifndef SIMPSONSOLVER_HPP
#define SIMPSONSOLVER_HPP

#include "AbstractIntegralSolver.hpp"

class SimpsonSolver : public AbstractIntegralSolver {
public:
  SimpsonSolver();
  virtual ~SimpsonSolver();

  double SolveIntegral();
};

#endif /* TRAPEZSOLVER_HPP */
