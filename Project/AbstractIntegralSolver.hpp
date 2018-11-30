/*
 * AbstractIntegralSolver.hpp
 *
 *  Created on: Nov 25, 2018
 *      Author: beschenk
 */

#ifndef ABSTRACTINTEGRALSOLVER_HPP
#define ABSTRACTINTEGRALSOLVER_HPP

#include <ostream>

class AbstractIntegralSolver {
public:
  // Constructor and destructor
  AbstractIntegralSolver();
  AbstractIntegralSolver(int numberOfSteps, double initialArgument, double finalArgument);
  virtual ~AbstractIntegralSolver();

  // Other public methods
  void SetNumberOfSteps(double n);
  void SetInterval(double x0, double xf);

  // TODO: How do you make this work?
  template <typename t> void SetFunction(t f) {
      function = f;
  }

  virtual double SolveIntegral() = 0;

  // Get methods
  double GetInitialArgument() const { return initialArgument; }
  double GetFinalArgument() const { return finalArgument; }
  double GetNumberOfSteps() const { return numberOfSteps; }
  double GetStepSize() const { return (finalArgument-initialArgument)/numberOfSteps; }

private:
  double numberOfSteps;
  double initialArgument;
  double finalArgument;
  template <typename  t> t function;
  //double (*function)(double x);
};

#endif /* ABSTRACTINTEGRALSOLVER_HPP */
