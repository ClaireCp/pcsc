cmake_minimum_required(VERSION 3.1)

# for doxygen use with versions older than 3.3
cmake_policy(VERSION 3.3)

set(CMAKE_CXX_STANDARD 14)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

################################################################
# Google test
################################################################

include(GoogleTest)
enable_testing()
find_package(GTest)
if (GTEST_FOUND)
    include_directories(${GTEST_INCLUDE_DIRS})
    add_executable(main Main.cpp AbstractIntegralSolver.cpp MidPointSolver.cpp TrapezSolver.cpp SimpsonSolver.cpp Abstract2DIntegralSolver.cpp Abstract2DIntegralSolver.hpp MidPoint2DSolver.cpp MidPoint2DSolver.hpp Simpson2DSolver.cpp Simpson2DSolver.hpp Trapez2DSolver.cpp Trapez2DSolver.hpp Tools.cpp Tools.hpp TestSuite.cpp TestSuite.hpp Abstract1DIntegralSolver.hpp)
    target_link_libraries(main ${GTEST_BOTH_LIBRARIES} pthread)
    gtest_discover_tests(main)
endif()


################################################################
# Doxygen
################################################################

find_package(Doxygen)
if (DOXYGEN_FOUND)

    # to set other options, read: https://cmake.org/cmake/help/v3.9/module/FindDoxygen.html
    doxygen_add_docs(
            doxygen
            ${PROJECT_SOURCE_DIR}
            COMMENT "Generate html pages"
    )
endif(DOXYGEN_FOUND)

