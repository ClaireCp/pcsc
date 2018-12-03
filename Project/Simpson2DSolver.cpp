//
// Created by claire on 25.11.18.
//

#include "Simpson2DSolver.h"

double Simpson2DSolver::SolveIntegral() {
    double Integral = 0;
    double h_x = GetStepSize();
    double h_y = GetStepSize_y();
    double x0 = GetInitialArgument();
    double y0 = GetInitialArgument_y();

    // Loop over x
    for (int i = 0; i < GetNumberOfSteps(); i++) {
        double x1=x0+i*h_x;
        double x2=x0+(i+0.5)*h_x;
        double x3=x0+(i+1)*h_x;

        // Loop over y
        for (int j = 0; j < GetNumberOfSteps_y(); j++) {
            double y1=y0+j*h_y;
            double y2=y0+(j+0.5)*h_y;
            double y3=y0+(j+1)*h_y;

            Integral+= h_x*h_y*((myFunction(x1,y1)+myFunction(x1,y3)+myFunction(x3,y1)+myFunction(x3,y3))+
                                4*(myFunction(x1,y2)+myFunction(x2,y1)+myFunction(x2,y3)+myFunction(x3,y2))+
                                16*myFunction(x2,y2))/36;

        }

    }
    return Integral;

}
