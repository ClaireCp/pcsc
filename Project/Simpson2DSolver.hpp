/*
 * Simpson2DSolver.hpp
 *
 *  Created on: November 25, 2018
 *      Author: Benjamin Schenk <benjamin.schenk@epfl.ch>
 */

#ifndef SIMPSON2DSOLVER_HPP
#define SIMPSON2DSOLVER_HPP

#include "Abstract2DIntegralSolver.hpp"

/**
 * Daughter Class of Abstract2DIntegralSolver which computes a 2D integral using the Simpson2D method.
 * The Simpson2D algorithm considers several values of the function and gives them different weights.
 */
class Simpson2DSolver : public Abstract2DIntegralSolver {

public:
    /**
     * namespace t is defined as a function which takes two doubles as an input and returns a double.
     */
    using t = std::function<double(double, double)>;

    /**
     * Constructor for Simpson2DSolver inherited of Abstract2DIntegralSolver
     * @param n_x number of steps in the x direction
     * @param x0 the beginning of the x interval
     * @param xf the end of the x interval
     * @param n_y number of steps in the y direction
     * @param y0 the beginning of the y interval
     * @param yf the end of the y interval
     * @param f function to integrate dependent on x and y
     */
    Simpson2DSolver(int n_x, double x0, double xf,
                    int n_y, double y0, double yf,
                    t f): Abstract2DIntegralSolver(n_x, x0, xf, n_y, y0, yf, f) {}

    /**
    * Overridden virtual function to solve the integral for the 2D simpson method
    * @return the calculated integral of f over the rectangular 2D domain
    */
    double SolveIntegral() override;
};


#endif // SIMPSON2DSOLVER_HPP
