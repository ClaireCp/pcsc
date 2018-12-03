/*
 * AbstractIntegralSolver is the abstract mother class for 1D and 2D abstract integral solvers.
 * It provides a basic constructor as well as methods that are common for both 1D and 2D numerical solvers.
 * In order to provide polymorphism to accept both 1D and 2D functions, this is a templated class.
 */

#ifndef ABSTRACTINTEGRALSOLVER_HPP
#define ABSTRACTINTEGRALSOLVER_HPP

#include <ostream>
#include <functional>
#include "Tools.h"

template <typename t>
class AbstractIntegralSolver  {
public:

  // Constructor
  AbstractIntegralSolver(int numberOfSteps, double initialArgument, double finalArgument, t function);

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

  t function;
private:
  double numberOfSteps;
  double initialArgument;
  double finalArgument;

};

template class AbstractIntegralSolver<std::function<double(double)>>;
template class AbstractIntegralSolver<std::function<double(double, double)>>;

#endif /* ABSTRACTINTEGRALSOLVER_HPP */

