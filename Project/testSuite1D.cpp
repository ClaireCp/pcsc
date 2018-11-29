//
// Created by claire on 29.11.18.
//

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

