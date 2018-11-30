/*
 * SimpsonSolver.hpp
 *
 *  Created on: Nov 25, 2018
 *      Author: beschenk
 */

#ifndef SIMPSONSOLVER_HPP
#define SIMPSONSOLVER_HPP

#include "AbstractIntegralSolver.hpp"
#include "Abstract1DIntegralSolver.h"

class SimpsonSolver : public Abstract1DIntegralSolver {
public:
    using t = std::function<double(double)>;

    SimpsonSolver(int n, double x0, double xf, t f): Abstract1DIntegralSolver(n, x0, xf, f) {}

    double SolveIntegral() override;
};

#endif /* TRAPEZSOLVER_HPP */
