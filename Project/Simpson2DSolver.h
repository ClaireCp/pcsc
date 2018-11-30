//
// Created by claire on 25.11.18.
//

/**

#ifndef SIMPSON2DSOLVER_H
#define SIMPSON2DSOLVER_H


#include "Abstract2DIntegralSolver.h"

class Simpson2DSolver : public Abstract2DIntegralSolver {

public:
    Simpson2DSolver(int n_x, double x0, double xf,
                    int n_y, double y0, double yf,
                    double (*my2DFunction)(double x, double y));

    double SolveIntegral();
};


#endif //SIMPSON2DSOLVER_H

 */