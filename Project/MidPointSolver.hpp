/*
 * MidPointSolver.hpp
 *
 *  Created on: Nov 25, 2018
 *      Author: beschenk
 */

#ifndef MIDPOINTSOLVER_HPP
#define MIDPOINTSOLVER_HPP

#include "AbstractIntegralSolver.hpp"
#include "Abstract1DIntegralSolver.h"

class MidPointSolver : public Abstract1DIntegralSolver {
public:
    using t = std::function<double(double)>;

    MidPointSolver(int n, double x0, double xf, t f): Abstract1DIntegralSolver(n, x0, xf, f) {}

    double SolveIntegral();
};

#endif /* MIDPOINTSOLVER_HPP */
