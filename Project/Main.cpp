/*
 * Main.cpp
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
#include "Abstract1DIntegralSolver.hpp"
#include "MidPointSolver.hpp"
#include "TrapezSolver.hpp"
#include "SimpsonSolver.hpp"
#include "Abstract2DIntegralSolver.hpp"
#include "MidPoint2DSolver.hpp"
#include "Trapez2DSolver.hpp"
#include "Simpson2DSolver.hpp"


#include <exception>
#include <gtest/gtest.h>

/** TODO:
 * -> is it bad practice to provide multiple constructors?
 * What if a constructor is empty, meaning that all necessary variables are not initialized on instantiation?
 * Should we keep such a constructor?
 * -> ask about the hierarchy we chose to implement with superclass for 1D case and subclass for 2D case, is it OK?
 * -> code clustering: is our code too clustered due to the use of 3 constructors?
 * -> Is it possible to make a constructor invisible to the main class, and only visible to subclasses? Such that
 * client code cannot use it directly?
 * -> coding conventions: spacing, lowercase letters for variables, ect...
 * -> doxygen documentation
 * -> how to use google testing?
 * -> would it be better to put class variables as public so as not to use getters in the subclasses and uncluster code?
*/




double function(double x) {
    return pow(x,2);
}

double function2D(double x, double y) {
    return y*pow(x, 2);
}


/*TEST(IntervalTest, reversed_intervals) {
   MidPointSolver* MSolver = new MidPointSolver(10, 12, -4, function);
   EXPECT_EQ(-4, MSolver->GetInitialArgument());
   EXPECT_EQ(12, MSolver->GetFinalArgument());
}
*/

int main(int argc, char* argv[])
{
	MidPointSolver* MSolver = new MidPointSolver(10, 0, 2, function);
    double MIntegral = MSolver->SolveIntegral();
    std::cout << "Integral of x² from 0 to 2 using MidPoint " << MIntegral << std::endl;

    MidPoint2DSolver* M2DSolverBis = new MidPoint2DSolver(10, 0, 2, 10, 0, 2, function2D);
    double M2DIntegralBis = M2DSolverBis->SolveIntegral();
    std::cout << "Integral of y*x² from 0 to 2 using MidPoint2D " << M2DIntegralBis << std::endl;

    SimpsonSolver* SSolver = new SimpsonSolver(10, 0, 2, function);
    double SIntegral = SSolver->SolveIntegral();
    std::cout << "Integral of x² from 0 to 2 using Simpson " << SIntegral << std::endl;

    Simpson2DSolver* S2DSolverBis = new Simpson2DSolver(10, 0, 2, 10, 0, 2, function2D);
    double S2DIntegralBis = S2DSolverBis->SolveIntegral();
    std::cout << "Integral of y*x² from 0 to 2 using Simpson2D " << S2DIntegralBis << std::endl;

    TrapezSolver* TSolver = new TrapezSolver(10, 0, 2, function);
    double TIntegral = TSolver->SolveIntegral();
    std::cout << "Integral of x² from 0 to 2 using Trapez " << TIntegral << std::endl;

    Trapez2DSolver* T2DSolverBis = new Trapez2DSolver(10, 0, 2, 10, 0, 2, function2D);
    double T2DIntegralBis = T2DSolverBis->SolveIntegral();
    std::cout << "Integral of y*x² from 0 to 2 using Trapez2D " << T2DIntegralBis << std::endl;

    MidPoint2DSolver* M2DSolver = new MidPoint2DSolver(3, 0.1, 1.1, 3, 0.2, 1.2, function2D);
    double M2DIntegral = M2DSolver->SolveIntegral();
    std::cout << M2DIntegral << std::endl;

    Simpson2DSolver* S2DSolver = new Simpson2DSolver(3, 0.1, 1.1, 3, 0.2, 1.2, function2D);
    double S2DIntegral = S2DSolver->SolveIntegral();
    std::cout << S2DIntegral << std::endl;

    Trapez2DSolver* T2DSolver = new Trapez2DSolver(3, 0.1, 1.1, 3, 0.2, 1.2, function2D);
    double T2DIntegral = T2DSolver->SolveIntegral();
    std::cout << T2DIntegral << std::endl;

/*    testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();

*/

	/**
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

    MidPoint2DSolver* M2Dsolver = new MidPoint2DSolver(10,0,2,10,0,2,function2D);
    double M2Dintegral= M2Dsolver->SolveIntegral();
    std::cout << M2Dintegral << std::endl;
    delete M2Dsolver;

    Trapez2DSolver* T2Dsolver = new Trapez2DSolver(10,0,2,10,0,2,function2D);
    double T2Dintegral=T2Dsolver->SolveIntegral();
    std::cout << T2Dintegral << std::endl;

    Simpson2DSolver* S2Dsolver = new Simpson2DSolver(10,0,2,10,0,2,function2D);
    double S2Dintegral=S2Dsolver->SolveIntegral();
    std::cout << S2Dintegral << std::endl;


    // Check if overloaded constructor works
    MidPointSolver* MSolver2 = new MidPointSolver(10, 0, 2);
    MSolver2->SetFunction(function);
    std::cout << "MSolver2->initialArgument = " << MSolver2->GetInitialArgument() << std::endl;
    std::cout << "MSolver2->finalArgument = " << MSolver2->GetFinalArgument() << std::endl;
    double MIntegral2= MSolver2->SolveIntegral();
    std::cout << "Constructor overload works: " << MIntegral2 << std::endl;

    // Check if 2D solver behaves and builds functions correctly
    MidPoint2DSolver* M2DSolver = new MidPoint2DSolver(3, 0.1, 1.1, 3, 0.2, 1.2, function2D);
    std::cout << "M2DSolver2->initialArgument_x = " << M2DSolver->GetInitialArgument() << std::endl;
    std::cout << "M2DSolver2->finalArgument_x = " << M2DSolver->GetFinalArgument() << std::endl;
    std::cout << "M2DSolver2->initialArgument_y = " << M2DSolver->GetInitialArgument_y() << std::endl;
    std::cout << "M2DSolver2->finalArgument_y = " << M2DSolver->GetFinalArgument_y() << std::endl;
    std::flush(std::cout);
    double M2DIntegral = M2DSolver->SolveIntegral();
    std::cout << "Abstract and concrete 2D works: " << M2DIntegral << std::endl;

    // Check if parameter check works
    //MidPoint2DSolver* M2DSolverWrongParams = new MidPoint2DSolver(-4, 0.1, 1.1, 3, 0.2, 1.2, function2D);

    // Check if wrong interval is corrected (2D case)
    MidPoint2DSolver* M2DSolverWrongParams = new MidPoint2DSolver(4, 3, 1, 6, 3, 1, function2D);
    std::cout << "M2DSolver2WrongParams->initialArgument_x = " << M2DSolverWrongParams->GetInitialArgument() << std::endl;
    std::cout << "M2DSolver2WrongParams->finalArgument_x = " << M2DSolverWrongParams->GetFinalArgument() << std::endl;
    std::cout << "M2DSolver2WrongParams->initialArgument_y = " << M2DSolverWrongParams->GetInitialArgument_y() << std::endl;
    std::cout << "M2DSolver2WrongParams->finalArgument_y = " << M2DSolverWrongParams->GetFinalArgument_y() << std::endl;

    // Check if wrong interval is corrected for 1D case
    MidPointSolver* MSolverWrongParams = new MidPointSolver(4, 9, -5);
    std::cout << "MSolverWrongParams->initialArgument = " << MSolverWrongParams->GetInitialArgument() << std::endl;
    std::cout << "MSolverWrongParams->finalArgument = " << MSolverWrongParams->GetFinalArgument() << std::endl;

<<<<<<< HEAD
    // Check if third overloaded constructor works
    MidPointSolver* MSolverThirdConstructor = new MidPointSolver(10, 0., 2., function);
    double MIntegralThirdConstructor = MSolverThirdConstructor->SolveIntegral();
    std::cout << "Check if third overloaded constructor works:" << MIntegralThirdConstructor << std::endl;
=======
>>>>>>> 5049ae93514c0a2a777aae95b947bac13fbdba6d

	 */
    return 0;
}
