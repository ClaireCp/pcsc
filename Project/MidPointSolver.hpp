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
    //MidPointSolver();
    //MidPointSolver(int numberOfSteps, double initialArgument, double finalArgument);
    MidPointSolver(int numberOfSteps, double initialArgument, double finalArgument, t function): Abstract1DIntegralSolver(numberOfSteps, initialArgument, finalArgument, function) {}
    //virtual ~MidPointSolver();

    double SolveIntegral();
};

#endif /* MIDPOINTSOLVER_HPP */
