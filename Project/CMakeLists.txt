include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_executable(main Main.cpp AbstractIntegralSolver.cpp MidPointSolver.cpp TrapezSolver.cpp SimpsonSolver.cpp Abstract2DIntegralSolver.cpp Abstract2DIntegralSolver.hpp MidPoint2DSolver.cpp MidPoint2DSolver.hpp Simpson2DSolver.cpp Simpson2DSolver.hpp Trapez2DSolver.cpp Trapez2DSolver.hpp Tools.cpp Tools.hpp TestSuite.cpp TestSuite.hpp Abstract1DIntegralSolver.hpp)
