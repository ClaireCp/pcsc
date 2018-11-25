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

double function(double x) {
    return pow(x,2);
}

int main(int argc, char* argv[])
{
	MidPointSolver* Solver = new MidPointSolver;
	Solver->SetFunction(function);
	Solver->SetInterval(0, 2);
	Solver->SetNumberOfSteps(1000);
	double Integral= Solver->SolveIntegral();

	std::cout << Integral << std::endl;
    return 0;
}

