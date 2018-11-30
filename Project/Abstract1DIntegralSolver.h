//
// Created by claire on 30.11.18.
//

#ifndef ABSTRACT1DINTEGRALSOLVER_H
#define ABSTRACT1DINTEGRALSOLVER_H

#include "AbstractIntegralSolver.hpp"


class Abstract1DIntegralSolver: public AbstractIntegralSolver <std::function<double(double)>> {
public:
    using t = std::function<double(double)>;

    //Constructor and destructor
    Abstract1DIntegralSolver(int n, double x0, double xf, t f): AbstractIntegralSolver(n, x0, xf, f) {};

    double SolveIntegral();

    //double Abstract1DIntegralSolver::myFunction(double x) const {

    //}

    //~Abstract1DIntegralSolver() {}

    //double myFunction(double x) const {
    //    return f(x);
    //}

};

#endif //ABSTRACT1DINTEGRALSOLVER_H
