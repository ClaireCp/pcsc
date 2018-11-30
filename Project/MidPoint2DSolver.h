//
// Created by claire on 25.11.18.
//


#ifndef MIDPOINT2DSOLVER_H
#define MIDPOINT2DSOLVER_H

#include "Abstract2DIntegralSolver.h"

class MidPoint2DSolver : public Abstract2DIntegralSolver {

public:
    using t = std::function<double(double, double)>;

    MidPoint2DSolver(int n_x, double x0, double xf,
                     int n_y, double y0, double yf,
                     t f): Abstract2DIntegralSolver(n_x, x0, xf, n_y, y0, yf, f) {}

    double SolveIntegral();
};

#endif //MIDPOINT2DSOLVER_H
