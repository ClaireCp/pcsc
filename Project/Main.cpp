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
#include <gtest/gtest-death-test.h>

/** TODO:


 * -> coding conventions: spacing, lowercase letters for variables, ect...
 * -> would it be better to put class variables as public so as not to use getters in the subclasses and uncluster code?
*/


double function(double x) {
    return pow(x,2);
}

double function2D(double x, double y) {
    return y*pow(x, 2);
}

TEST(WrongN, negative_n)  {
    ASSERT_EXIT( {new MidPointSolver(-10, 12, -4, function); }, ::testing::ExitedWithCode(1), "The number of iteration has to be strictly superior to 0.");
}

TEST(IntervalTest, reversed_intervals) {
   MidPointSolver* MSolver = new MidPointSolver(10, 12, -4, function);
   EXPECT_EQ(-4, MSolver->GetInitialArgument());
   EXPECT_EQ(12, MSolver->GetFinalArgument());
   delete(MSolver);
}

TEST(MidPoint1DTest, normal_conditions) {
    MidPointSolver* MSolver = new MidPointSolver(10, 0, 2, function);
    double MIntegral = MSolver->SolveIntegral();
    double realValue = 2 + 2.0/3.0;
    EXPECT_NEAR(realValue, MIntegral, 0.1);
    delete(MSolver);
}

TEST(MidPoint2DTest, normal_conditions) {
    MidPoint2DSolver* M2DSolver = new MidPoint2DSolver(10, 0, 2, 10, 0, 2, function2D);
    double M2DIntegral = M2DSolver->SolveIntegral();
    double realValue = 5 + 1.0/3.0;
    EXPECT_NEAR(realValue, M2DIntegral, 0.1);
    delete(M2DSolver);
}

TEST(Simpson1DTest, normal_conditions) {
    SimpsonSolver* SSolver = new SimpsonSolver(10, 0, 2, function);
    double SIntegral = SSolver->SolveIntegral();
    double realValue = 2 + 2.0/3.0;
    EXPECT_NEAR(realValue, SIntegral, 0.1);
    delete(SSolver);
}

TEST(Simpson2DTest, normal_conditions) {
    Simpson2DSolver* S2DSolver = new Simpson2DSolver(10, 0, 2, 10, 0, 2, function2D);
    double S2DIntegral = S2DSolver->SolveIntegral();
    double realValue = 5 + 1.0/3.0;
    EXPECT_NEAR(realValue, S2DIntegral, 0.1);
    delete(S2DSolver);
}

TEST(TrapezTest, normal_conditions) {
    TrapezSolver* TSolver = new TrapezSolver(10, 0, 2, function);
    double TIntegral = TSolver->SolveIntegral();
    double realValue = 2 + 2.0/3.0;
    EXPECT_NEAR(realValue, TIntegral, 0.1);
    delete(TSolver);
}

TEST(Trapez2DTest, normal_conditions) {
    Trapez2DSolver* T2DSolver = new Trapez2DSolver(10, 0, 2, 10, 0, 2, function2D);
    double T2DIntegral = T2DSolver->SolveIntegral();
    double realValue = 5 + 1.0/3.0;
    EXPECT_NEAR(realValue, T2DIntegral, 0.1);
    delete(T2DSolver);
}


int main(int argc, char* argv[]) {

    testing::InitGoogleTest(&argc, argv);
    int i = RUN_ALL_TESTS();

    // Check if 2D solver behaves and builds functions correctly
    MidPoint2DSolver* M2DSolver = new MidPoint2DSolver(3, 0.1, 1.1, 3, 0.2, 1.2, function2D);
    std::cout << "M2DSolver2->initialArgument_x = " << M2DSolver->GetInitialArgument() << std::endl;
    std::cout << "M2DSolver2->finalArgument_x = " << M2DSolver->GetFinalArgument() << std::endl;
    std::cout << "M2DSolver2->initialArgument_y = " << M2DSolver->GetInitialArgument_y() << std::endl;
    std::cout << "M2DSolver2->finalArgument_y = " << M2DSolver->GetFinalArgument_y() << std::endl;
    std::flush(std::cout);
    double M2DIntegral = M2DSolver->SolveIntegral();
    std::cout << "Abstract and concrete 2D works: " << M2DIntegral << std::endl;

    // Check if wrong interval is corrected (2D case)
    MidPoint2DSolver* M2DSolverWrongParams = new MidPoint2DSolver(4, 3, 1, 6, 3, 1, function2D);
    std::cout << "M2DSolver2WrongParams->initialArgument_x = " << M2DSolverWrongParams->GetInitialArgument() << std::endl;
    std::cout << "M2DSolver2WrongParams->finalArgument_x = " << M2DSolverWrongParams->GetFinalArgument() << std::endl;
    std::cout << "M2DSolver2WrongParams->initialArgument_y = " << M2DSolverWrongParams->GetInitialArgument_y() << std::endl;
    std::cout << "M2DSolver2WrongParams->finalArgument_y = " << M2DSolverWrongParams->GetFinalArgument_y() << std::endl;

    return 0;
}

