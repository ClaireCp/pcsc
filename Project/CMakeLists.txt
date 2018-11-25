include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_executable(SolveIntegeal SolveIntegeal.cpp AbstractIntegralSolver.cpp MidPointSolver.cpp)
