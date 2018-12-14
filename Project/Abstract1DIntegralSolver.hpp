/*
 * Abstract1DIntegralSolver.hpp
 *
 *  Created on: November 25, 2018
 *      Author: Claire Capelo <claire.capelo@epfl.ch>
 */


#ifndef ABSTRACT1DINTEGRALSOLVER_HPP
#define ABSTRACT1DINTEGRALSOLVER_HPP

#include "AbstractIntegralSolver.hpp"

/**
 * Abstract1DIntegralSolver is the abstract mother class for 1D integral solvers.
 * It defines the constructor for the 1D integral solver, which is simply the constructor of its mother class
 * and the type of the function.
 */
class Abstract1DIntegralSolver: public AbstractIntegralSolver <std::function<double(double)>> {
public:
    /**
     * namespace t is defined as a function which takes one double as an argument and returns a double.
     */
    using t = std::function<double(double)>;

    //Constructor
    /**
    * Constructor for Abstract1DIntegralSolver inherited of AbstractIntegralSolver
    * @param n number of steps in the x direction
    * @param x0 the beginning of the x interval
    * @param xf the end of the x interval
    * @param f function to integrate dependent on x
    */
    Abstract1DIntegralSolver(int n, double x0, double xf, t f): AbstractIntegralSolver(n, x0, xf, f) {};

    /**
    * Method to get the value of the function at x
    * @param x the argument of the function
    * @return the value of the function at x
    */
    double GetFunctionValue(double x) const {
        return function(x);
    }

};

#endif //ABSTRACT1DINTEGRALSOLVER_HPP
