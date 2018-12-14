/*
 * AbstractIntegralSolver.hpp
 *
 *  Created on: November 25, 2018
 *      Author: Benjamin Schenk <benjamin.schenk@epfl.ch>
 */


#ifndef ABSTRACTINTEGRALSOLVER_HPP
#define ABSTRACTINTEGRALSOLVER_HPP

#include <ostream>
#include <functional>
#include "Tools.hpp"

/**
 * AbstractIntegralSolver is the abstract mother class for 1D and 2D abstract integral solvers.
 * It provides a basic constructor as well as methods that are common for both 1D and 2D numerical solvers.
 * In order to provide polymorphism to accept both 1D and 2D functions, this is a templated class.
 */
template <typename t>
class AbstractIntegralSolver  {
public:

  // Constructors
  /**
   * Constructor with every necessary argument
   * @param numberOfSteps the number of steps
   * @param initialArgument the beginning of the interval
   * @param finalArgument the end of the interval
   * @param function the function
   */
  AbstractIntegralSolver(int numberOfSteps, double initialArgument, double finalArgument, t function);

  // Other public methods
  /**
   * Method to set the number of steps / the number of sub intervals
   * @param n the number of steps
   */
  void SetNumberOfSteps(const double n) {
      checkNumberOfSteps(n);
      numberOfSteps = n;
  }
  /**
   * Method to set the interval in which the function will be integrated
   * @param x0 the initial argument
   * @param xf the final argument
   */
  void SetInterval(double x0, double xf) {
      checkInterval(&x0, &xf);
      initialArgument = x0;
      finalArgument = xf;
  }
  /**
   * Method to set the function of type t
   * @param f the function of type t
   */
  void SetFunction(t f) {
      function = f;
  }

  /**
   * Virtual method to solve the integral
   * @return integral of the function over the given domain
   */
  virtual double SolveIntegral() = 0;

  // Get methods
  /**
   * Method to access to the beginning of the interval
   * @return the initial argument
   */
  double GetInitialArgument() const { return initialArgument; }
  /**
   * Method to access to the end of the interval
   * @return the final argument
   */
  double GetFinalArgument() const { return finalArgument; }
  /**
   * Method to access to the number of steps used
   * @return the number of steps
   */
  double GetNumberOfSteps() const { return numberOfSteps; }
  /**
   * Method to calculate the step size which is function of the interval and the number of steps
   * @return the step size
   */
  double GetStepSize() const { return (finalArgument-initialArgument)/numberOfSteps; }

  t function;

private:
  double numberOfSteps;
  double initialArgument;
  double finalArgument;

};

template class AbstractIntegralSolver<std::function<double(double)>>;
template class AbstractIntegralSolver<std::function<double(double, double)>>;

#endif // ABSTRACTINTEGRALSOLVER_HPP

