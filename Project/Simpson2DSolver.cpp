/*
 * Simpson2DSolver.cpp
 *
 *  Created on: November 25, 2018
 *      Author: Benjamin Schenk <benjamin.schenk@epfl.ch>
 */

#include "Simpson2DSolver.hpp"

double Simpson2DSolver::SolveIntegral() {
    double Integral = 0;
    double h_x = GetStepSize();
    double h_y = GetStepSize_y();
    double x0 = GetInitialArgument();
    double y0 = GetInitialArgument_y();

    // Loop over number of steps in x direction
    for (int i = 0; i < GetNumberOfSteps(); i++) {
        // argument where the x sub interval begins
        double x1=x0+i*h_x;
        // center of the x sub interval
        double x2=x0+(i+0.5)*h_x;
        // argument where the x sub interval ends
        double x3=x0+(i+1)*h_x;

        // Loop over number of steps in y direction
        for (int j = 0; j < GetNumberOfSteps_y(); j++) {
            // argument where the y sub interval begins
            double y1=y0+j*h_y;
            // center of the y sub interval
            double y2=y0+(j+0.5)*h_y;
            // argument where the y sub interval end
            double y3=y0+(j+1)*h_y;

            // Evaluation of the function and weighted adding
            Integral+= h_x*h_y*((GetFunctionValue(x1,y1)+GetFunctionValue(x1,y3)+GetFunctionValue(x3,y1)
                                +GetFunctionValue(x3,y3))
                            +4*(GetFunctionValue(x1,y2)+GetFunctionValue(x2,y1)+GetFunctionValue(x2,y3)
                                +GetFunctionValue(x3,y2))
                            +16*GetFunctionValue(x2,y2))/36;

        }

    }
    return Integral;

}
