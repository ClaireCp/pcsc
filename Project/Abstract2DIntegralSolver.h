//
// Created by claire on 25.11.18.
//
/**
#include "AbstractIntegralSolver.hpp"

#ifndef ABSTRACT2DINTEGRALSOLVER_H
#define ABSTRACT2DINTEGRALSOLVER_H

class Abstract2DIntegralSolver: public AbstractIntegralSolver {
public:
    // Constructor and destructor
    Abstract2DIntegralSolver(int numberOfSteps_x, double x0, double xf,
                             int numberOfSteps_y, double y0, double yf,
                             double (*my2DFunction)(double x, double y));
    virtual ~Abstract2DIntegralSolver();

    // Other public methods
    void SetNumberOfSteps_y(double n);
    void SetInterval_y(double y0, double yf);
    void SetFunction_xy(double (*f_xy)(double x, double y));

    double my2DFunction_xy(double x, double y) const;
    virtual double SolveIntegral() = 0;

    // Get methods
    double GetInitialArgument_y() const { return initialArgument_y; }
    double GetFinalArgument_y() const { return finalArgument_y; }
    double GetNumberOfSteps_y() const { return numberOfSteps_y; }
    double GetStepSize_y() const { return (finalArgument_y-initialArgument_y)/numberOfSteps_y; }

private:
    double numberOfSteps_y;
    double initialArgument_y;
    double finalArgument_y;
    double (*function_xy)(double x, double y);
};

#endif //2DABSTRACTINTEGRALSOLVER_H

 */