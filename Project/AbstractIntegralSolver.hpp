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
  virtual ~AbstractIntegralSolver();

  // Other public methods
  void SetNumberOfSteps(const double n);
  void SetInterval(const double x0, const double xf);
  void SetFunction(double (*f)(double x));

  double myFunction(double x) const;
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
  double (*function)(double x);
};

#endif /* ABSTRACTINTEGRALSOLVER_HPP */
