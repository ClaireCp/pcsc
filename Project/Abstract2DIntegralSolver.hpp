/*
 * Abstract1DIntegralSolver.hpp
 *
 *  Created on: November 25, 2018
 *      Author: Claire Capelo <claire.capelo@epfl.ch>
 */

#include "AbstractIntegralSolver.hpp"

#ifndef ABSTRACT2DINTEGRALSOLVER_HPP
#define ABSTRACT2DINTEGRALSOLVER_HPP

/**
 * Abstract2DIntegralSolver is the abstract mother class for 2D integral solvers.
 * It defines a new constructor for 2D integrals, the necessary methods in the y direction and the type
 * of the function
 */
class Abstract2DIntegralSolver: public AbstractIntegralSolver <std::function<double(double, double)>> {
public:
    /**
     * namespace t is defined as a function which takes two double as arguments and returns a double.
     */
    using t = std::function<double(double, double)>;

    // Constructor
    /**
     * New constructor for 2D integrals
     * @param n_x the number of steps in the x direction
     * @param x0 the beginning of the x interval
     * @param xf the end of the x interval
     * @param n_y the number of steps in the y direction
     * @param y0 the beginning of the y interval
     * @param yf the end of the y interval
     * @param f the function dependent on x and y
     */
    Abstract2DIntegralSolver(int n_x, double x0, double xf,
                             int n_y, double y0, double yf,
                             t f);

    // Other public methods
    /**
     * Method to get the value of the function
     * @param x the x argument
     * @param y the y argument
     * @return the value of the function at x and y
     */
    double GetFunctionValue(double x, double y) const {
        return function(x, y);
    }

    // Get methods
    /**
     * Method to access to the beginning of the y interval
     * @return the initial y argument
     */
    double GetInitialArgument_y() const { return initialArgument_y; }
    /**
     * Method to access to the end of the y interval
     * @return the final y argument
     */
    double GetFinalArgument_y() const { return finalArgument_y; }
    /**
     * Method to access to the number of steps used in y direction
     * @return the number of steps in y direction
     */
    double GetNumberOfSteps_y() const { return numberOfSteps_y; }
    /**
     * Method to calculate the step size in y direction which is function of the interval and the number of steps
     * @return the step size in y direction
     */
    double GetStepSize_y() const { return (finalArgument_y-initialArgument_y)/numberOfSteps_y; }

private:
    double numberOfSteps_y;
    double initialArgument_y;
    double finalArgument_y;
};

#endif // ABSTRACT2DINTEGRALSOLVER_HPP

