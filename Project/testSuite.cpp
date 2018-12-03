//
// Created by claire on 29.11.18.
//
/**

#include "testSuite.h"
#include "MidPointSolver.hpp"
#include <cmath>
#include <exception>
#include <gtest/gtest.h>

double function(double x) {
    return pow(x,2);
}

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(IntervalTest, reversed_intervals) {
    MidPointSolver *midPointSolver = new MidPointSolver(3, 12, -4, function);
    EXPECT_EQ(-4, midPointSolver->GetInitialArgument());
    EXPECT_EQ(12, midPointSolver->GetFinalArgument());
}


TEST(FullConstructor, base_case) {
    MidPointSolver *midPointSolver2 = new MidPointSolver(10, 0, 2, function);
    double mIntegral2 = midPointSolver2->SolveIntegral();
    ASSERT_FLOAT_EQ(2.66, mIntegral2);
}

*/

