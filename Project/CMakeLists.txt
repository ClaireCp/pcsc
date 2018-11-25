include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_executable(main main.cpp AbstractIntegralSolver.cpp MidPointSolver.cpp TrapezSolver.cpp SimpsonSolver.cpp Abstract2DIntegralSolver.cpp Abstract2DIntegralSolver.h MidPoint2DSolver.cpp MidPoint2DSolver.h Simpson2DSolver.cpp Simpson2DSolver.h)
