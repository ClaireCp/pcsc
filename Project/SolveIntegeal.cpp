/*
 * SolveIntegral.cpp
 *
 * <--- Description of the program goes here.
 *
 * Created on: November 25, 2018
 * 	   Author: Benjamin Schenk <benjamin.schenk@epfl>
 */

/*
 * Any headers you need to include should be specified on the next lines
 */
#include <iostream>
#include <cmath>
#include "AbstractIntegralSolver.hpp"
#include "MidPointSolver.hpp"
#include "TrapezSolver.hpp"
#include "SimpsonSolver.hpp"

double function(double x) {
    return pow(x,2);
}

int main(int argc, char* argv[])
{
	MidPointSolver* MSolver = new MidPointSolver;
	MSolver->SetFunction(function);
	MSolver->SetInterval(0, 2);
	MSolver->SetNumberOfSteps(10);

	double MIntegral= MSolver->SolveIntegral();
	std::cout << MIntegral << std::endl;
    delete MSolver;


    TrapezSolver* TSolver = new TrapezSolver;
    TSolver->SetFunction(function);
    TSolver->SetInterval(0, 2);
    TSolver->SetNumberOfSteps(10);

    double TIntegral= TSolver->SolveIntegral();
    std::cout << TIntegral << std::endl;
    delete TSolver;


    SimpsonSolver* SSolver = new SimpsonSolver;
    SSolver->SetFunction(function);
    SSolver->SetInterval(0, 2);
    SSolver->SetNumberOfSteps(10);

    double SIntegral= SSolver->SolveIntegral();
    std::cout << SIntegral << std::endl;
    delete SSolver;

    return 0;
}

