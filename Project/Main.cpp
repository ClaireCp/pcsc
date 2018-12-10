/*
 * Main.cpp
 *
 * Created on: December 1, 2018
 * 	   Author: Benjamin Schenk <benjamin.schenk@epfl>
 */


#include "AbstractIntegralSolver.hpp"
#include "Abstract1DIntegralSolver.hpp"
#include "MidPointSolver.hpp"
#include "TrapezSolver.hpp"
#include "SimpsonSolver.hpp"
#include "Abstract2DIntegralSolver.hpp"
#include "MidPoint2DSolver.hpp"
#include "Trapez2DSolver.hpp"
#include "Simpson2DSolver.hpp"

#include <iostream> // Needed to print results to console
#include <cmath>    // Needed to define the functions (ex.: pow(x,2), sin(x))

/**
 * 1D Function the user wishes to integrate
 * @param x is the argument of the function
 * @return the value of the function at the point x
 */
double function(double x) {
    return pow(x,2);
}


/**
 * 2D Function the user wishes to integrate
 * @param x the first argument of the function
 * @param y the second argument of the function
 * @return the value of the function at the point (x, y)
 */
double function2D(double x, double y) {
    return y*pow(x, 2);
}


int main(int argc, char* argv[]) {

    // Example on how to calculate the integral of the 1D function using the Simpson solver
    SimpsonSolver* SSolver = new SimpsonSolver(1, 0.0, 2.0, function);
    double SIntegral = SSolver->SolveIntegral();
    std::cout << "The integral of x² between " << SSolver->GetInitialArgument() << " and "
              << SSolver->GetFinalArgument() << " is " << SIntegral << std::endl;
    delete(SSolver);


    // Example on how to calculate the integral of the 2D function using the Simpson 2D solver
    Simpson2DSolver* S2DSolver = new Simpson2DSolver(1, 0.0, 2.0, 1, 0.0, 2.0, function2D);
    double S2DIntegral = S2DSolver->SolveIntegral();
    std::cout << "The integral of y*x² with x between [" << S2DSolver->GetInitialArgument() << ", "
              << S2DSolver->GetFinalArgument() << "] and y between [" << S2DSolver->GetInitialArgument_y() << ", "
              << S2DSolver->GetFinalArgument_y() << "] is " << S2DIntegral << std::endl;
    delete(SSolver);

    return 0;
}

