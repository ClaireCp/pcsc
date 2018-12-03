/*
 * Abstract1DIntegralSolver is the abstract mother class for 1D integral solvers.
 * It only defines the constructor for the 1D integral solver, which is simply the constructor of its mother class.
 */

#ifndef ABSTRACT1DINTEGRALSOLVER_H
#define ABSTRACT1DINTEGRALSOLVER_H

#include "AbstractIntegralSolver.hpp"


class Abstract1DIntegralSolver: public AbstractIntegralSolver <std::function<double(double)>> {
public:
    using t = std::function<double(double)>;

    //Constructor
    Abstract1DIntegralSolver(int n, double x0, double xf, t f): AbstractIntegralSolver(n, x0, xf, f) {};

};

#endif //ABSTRACT1DINTEGRALSOLVER_H
