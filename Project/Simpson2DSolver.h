//
// Created by claire on 25.11.18.
//


#ifndef SIMPSON2DSOLVER_H
#define SIMPSON2DSOLVER_H


#include "Abstract2DIntegralSolver.h"

class Simpson2DSolver : public Abstract2DIntegralSolver {

public:
    using t = std::function<double(double, double)>;

    Simpson2DSolver(int n_x, double x0, double xf,
                    int n_y, double y0, double yf,
                    t f): Abstract2DIntegralSolver(n_x, x0, xf, n_y, y0, yf, f) {}

    double SolveIntegral() override;
};


#endif //SIMPSON2DSOLVER_H
