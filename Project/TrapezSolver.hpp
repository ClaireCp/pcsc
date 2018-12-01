/*
 * TrapezSolver.hpp
 *
 *  Created on: Nov 25, 2018
 *      Author: beschenk
 */

#ifndef TRAPEZSOLVER_HPP
#define TRAPEZSOLVER_HPP

#include "AbstractIntegralSolver.hpp"
#include "Abstract1DIntegralSolver.h"


class TrapezSolver : public Abstract1DIntegralSolver {
public:
    using t = std::function<double(double)>;

    TrapezSolver(int n, double x0, double xf, t f): Abstract1DIntegralSolver(n, x0, xf, f) {}

    double SolveIntegral() override;
};

#endif // TRAPEZSOLVER_HPP
