//
// Created by claire on 30.11.18.
//

#ifndef ABSTRACT1DINTEGRALSOLVER_H
#define ABSTRACT1DINTEGRALSOLVER_H

#include "AbstractIntegralSolver.hpp"

class Abstract1DIntegralSolver: public AbstractIntegralSolver {
public:
    //Constructor and destructor
    Abstract1DIntegralSolver(int numberOfSteps, double x0, double xf, double (*my1DFunction)(double x))

    virtual ~Abstract1DIntegralSolver() {}

};

#endif //ABSTRACT1DINTEGRALSOLVER_H
