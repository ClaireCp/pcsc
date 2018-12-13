/*
 * Test.cpp
 *
 * Created on: December 10, 2018
 * 	   Author: Claire Capelo <claire.capelo@epfl>
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

#include <cmath>                        // Needed to define the functions (ex.: pow(x,2), sin(x))
#include <gtest/gtest.h>                // Needed to perform the google tests
#include <gtest/gtest-death-test.h>     // Needed to perform the google death test


/**
 * 1D function which is used for testing
 * @param x the argument of the function
 * @return the value of the function at x
 */
double function(double x) {
    return pow(x,2);
}

/**
 * 2D Function which is used for testing
 * @param x the first argument of the function
 * @param y the second argument of the function
 * @return the value of the function at the point (x, y)
 */
double function2D(double x, double y) {
    return y*pow(x, 2);
}


/**
 * Test to ensure that the program crashes when a negative step number is given to a 1D-solver
 */
TEST(WrongStepNumber, negative_step_number)  {
    ASSERT_EXIT( {new MidPointSolver(-10, 12, -4, function); }, ::testing::ExitedWithCode(1), "The number of iteration has to be strictly superior to 0.");
}

/**
 * Test to ensure that the 1D-solver works even when the interval is given reversed
 */
TEST(IntervalTest, reversed_intervals) {
   MidPointSolver* MSolver = new MidPointSolver(10, 12, -4, function);
   EXPECT_EQ(-4, MSolver->GetInitialArgument());
   EXPECT_EQ(12, MSolver->GetFinalArgument());
   delete(MSolver);
}

/**
 * Test to control the functioning of the mid-point 1D-solver by comparing with the analytical solution
 */
TEST(MidPoint1DTest, normal_conditions) {
    MidPointSolver* MSolver = new MidPointSolver(10, 0, 2, function);
    double MIntegral = MSolver->SolveIntegral();
    double realValue = 2 + 2.0/3.0;
    EXPECT_NEAR(realValue, MIntegral, 0.1);
    delete(MSolver);
}

/**
 * Test to control the functioning of the mid-point 2D-solver by comparing with the analytical solution
 */
TEST(MidPoint2DTest, normal_conditions) {
    MidPoint2DSolver* M2DSolver = new MidPoint2DSolver(10, 0, 2, 10, 0, 2, function2D);
    double M2DIntegral = M2DSolver->SolveIntegral();
    double realValue = 5 + 1.0/3.0;
    EXPECT_NEAR(realValue, M2DIntegral, 0.1);
    delete(M2DSolver);
}

/**
 * Test to control the functioning of the simpson 1D-solver by comparing with the analytical solution
 */
TEST(Simpson1DTest, normal_conditions) {
    SimpsonSolver* SSolver = new SimpsonSolver(10, 0, 2, function);
    double SIntegral = SSolver->SolveIntegral();
    double realValue = 2 + 2.0/3.0;
    EXPECT_NEAR(realValue, SIntegral, 0.1);
    delete(SSolver);
}

/**
 * Test to control the functioning of the simpson 2D-solver by comparing with the analytical solution
 */
TEST(Simpson2DTest, normal_conditions) {
    Simpson2DSolver* S2DSolver = new Simpson2DSolver(10, 0, 2, 10, 0, 2, function2D);
    double S2DIntegral = S2DSolver->SolveIntegral();
    double realValue = 5 + 1.0/3.0;
    EXPECT_NEAR(realValue, S2DIntegral, 0.1);
    delete(S2DSolver);
}

/**
 * Test to control the functioning of the trapez 1D-solver by comparing with the analytical solution
 */
TEST(TrapezTest, normal_conditions) {
    TrapezSolver* TSolver = new TrapezSolver(10, 0, 2, function);
    double TIntegral = TSolver->SolveIntegral();
    double realValue = 2 + 2.0/3.0;
    EXPECT_NEAR(realValue, TIntegral, 0.1);
    delete(TSolver);
}

/**
 * Test to control the functioning of the trapez 2D-solver by comparing with the analytical solution
 */
TEST(Trapez2DTest, normal_conditions) {
    Trapez2DSolver* T2DSolver = new Trapez2DSolver(10, 0, 2, 10, 0, 2, function2D);
    double T2DIntegral = T2DSolver->SolveIntegral();
    double realValue = 5 + 1.0/3.0;
    EXPECT_NEAR(realValue, T2DIntegral, 0.1);
    delete(T2DSolver);
}



