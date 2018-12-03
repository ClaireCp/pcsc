//
// Created by claire on 25.11.18.
//


#ifndef MIDPOINT2DSOLVER_H
#define MIDPOINT2DSOLVER_H

#include "Abstract2DIntegralSolver.h"

/**
 * Daughter Class of Abstract2DIntegralSolver which computes a 2D integral using the Midpoint2D method.
 * The Midpoint2D algorithm takes the function value in the middle of the square of length h_x and h_y.
 */
class MidPoint2DSolver : public Abstract2DIntegralSolver {

public:
    /**
     * namespace t is defined as a function which takes two double as an input and returns a double.
     */
    using t = std::function<double(double, double)>;

    /**
     * Constructor for MidPoint2DSolver inherited of Abstract2DIntegralSolver
     * @param n_x number of steps in the x direction
     * @param x0 the beginning of the x interval
     * @param xf the end of the x interval
     * @param n_y number of steps in the y direction
     * @param y0 the beginning of the y interval
     * @param yf the end of the y interval
     * @param f function to integrate dependent on x and y
     */
    MidPoint2DSolver(int n_x, double x0, double xf,
                     int n_y, double y0, double yf,
                     t f): Abstract2DIntegralSolver(n_x, x0, xf, n_y, y0, yf, f) {}


    /**
     * Overridden virtual function to solve the integral for the 2D midpoint method
     * @return the calculated integral of f over the rectangular 2D domain
     */
    double SolveIntegral() override;
};

#endif //MIDPOINT2DSOLVER_H
