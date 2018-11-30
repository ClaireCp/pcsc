//
// Created by claire on 25.11.18.
//

/**
#ifndef MIDPOINT2DSOLVER_H
#define MIDPOINT2DSOLVER_H

#include "Abstract2DIntegralSolver.h"

class MidPoint2DSolver : public Abstract2DIntegralSolver {

public:
    MidPoint2DSolver(int n_x, double x0, double xf,
               int n_y, double y0, double yf,
               double (*my2DFunction)(double x, double y));

    double SolveIntegral();
};

#endif //MIDPOINT2DSOLVER_H
*/