/*
 * SimpsonSolver.hpp
 *
 *  Created on: November 25, 2018
 *      Author: Benjamin Schenk <benjamin.schenk@epfl.ch>
 */

#ifndef SIMPSONSOLVER_HPP
#define SIMPSONSOLVER_HPP

#include "Abstract1DIntegralSolver.hpp"

/**
 * Daughter Class of Abstract1DIntegralSolver which computes a 1D integral using the Simpson2D method.
 * The Simpson2D algorithm considers the extreme points of the sub interval with weight 1 and the middle of the
 * sub interval with weight 4.
 */
class SimpsonSolver : public Abstract1DIntegralSolver {
public:
    /**
     * namespace t is defined as a function which takes a double as an input and returns a double.
     */
    using t = std::function<double(double)>;

    /**
     * Constructor for SimpsonSolver inherited of Abstract1DIntegralSolver
     * @param n number of steps in the x direction
     * @param x0 the beginning of the x interval
     * @param xf the end of the x interval
     * @param f function to integrate over the interval [x0, xf] dependent on x
     */
    SimpsonSolver(int n, double x0, double xf, t f): Abstract1DIntegralSolver(n, x0, xf, f) {}

    /**
     * Overridden virtual function to solve the integral for the 1D simpson method
     * @return the calculated integral of f over the interval [x0, xf]
     */
    double SolveIntegral() override;
};

#endif
