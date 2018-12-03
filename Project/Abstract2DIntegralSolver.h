//
// Created by claire on 25.11.18.
//

#include "AbstractIntegralSolver.hpp"

#ifndef ABSTRACT2DINTEGRALSOLVER_H
#define ABSTRACT2DINTEGRALSOLVER_H

class Abstract2DIntegralSolver: public AbstractIntegralSolver <std::function<double(double, double)>> {
public:
    using t = std::function<double(double, double)>;

    // Constructor and destructor
    Abstract2DIntegralSolver(int n_x, double x0, double xf,
                             int n_y, double y0, double yf,
                             t f);
    virtual ~Abstract2DIntegralSolver() {}

    // Other public methods
    //void SetNumberOfSteps_y(double n);
    //void SetInterval_y(double y0, double yf);
    //void SetFunction_xy(double (*f_xy)(double x, double y));

    double myFunction(double x, double y) const {
        //std::cout << "In myFunction in Abstract2DIntegralSolver" << std::endl;
        return function(x, y);
    }


    // Get methods
    double GetInitialArgument_y() const { return initialArgument_y; }
    double GetFinalArgument_y() const { return finalArgument_y; }
    double GetNumberOfSteps_y() const { return numberOfSteps_y; }
    double GetStepSize_y() const { return (finalArgument_y-initialArgument_y)/numberOfSteps_y; }

private:
    double numberOfSteps_y;
    double initialArgument_y;
    double finalArgument_y;
};

#endif //2DABSTRACTINTEGRALSOLVER_H

