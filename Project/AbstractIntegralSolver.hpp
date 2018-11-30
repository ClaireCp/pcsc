/*
 * AbstractIntegralSolver.hpp
 *
 *  Created on: Nov 25, 2018
 *      Author: beschenk
 */

#ifndef ABSTRACTINTEGRALSOLVER_HPP
#define ABSTRACTINTEGRALSOLVER_HPP

#include <ostream>
#include <functional>
#include "Tools.h"

template <typename t>
class AbstractIntegralSolver  {
public:

  // Constructor and destructor
  //AbstractIntegralSolver();
  AbstractIntegralSolver(int numberOfSteps, double initialArgument, double finalArgument, t function);
  //virtual ~AbstractIntegralSolver();

  // Other public methods
  void SetNumberOfSteps(const double n) {
      checkNumberOfSteps(n);
      numberOfSteps = n;
  }

  void SetInterval(double x0, double xf) {
      checkInterval(&x0, &xf);
      initialArgument = x0;
      finalArgument = xf;
  }

  void SetFunction(t f) {
      function = f;
  }

  template <typename param> double myFunction(param x) const {
      return function(x);
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
  t function;
};

extern template class AbstractIntegralSolver<std::function<double(double)>>;


#endif /* ABSTRACTINTEGRALSOLVER_HPP */

