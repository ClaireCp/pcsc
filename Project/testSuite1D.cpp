//
// Created by claire on 29.11.18.
//
/**

#include "testSuite1D.h"
#include "MidPointSolver.hpp"
#include <cmath>
#include <exception>
#include <gtest/gtest.h>

double function(double x) {
    return pow(x,2);
}


TEST(IntervalTest, reversed_intervals) {
    MidPointSolver *midPointSolver = new MidPointSolver(3, 12, -4, function);
    EXPECT_EQ(-4, midPointSolver->GetInitialArgument());
    EXPECT_EQ(12, midPointSolver->GetFinalArgument());
}


TEST(EmptyConstructor, base_case) {
    MidPointSolver *midPointSolver1 = new MidPointSolver;
    midPointSolver1->SetNumberOfSteps(10);
    midPointSolver1->SetInterval(0, 2);
    midPointSolver1->SetFunction(function);
    double mIntegral1 = midPointSolver1->SolveIntegral();
    ASSERT_FLOAT_EQ(2.66, mIntegral1);
}

TEST(FullConstructor, base_case) {
    MidPointSolver *midPointSolver2 = new MidPointSolver(10, 0, 2, function);
    double mIntegral2 = midPointSolver2->SolveIntegral();
    ASSERT_FLOAT_EQ(2.66, mIntegral2);
}
*/


