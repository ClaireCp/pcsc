Project 7 - Numerical Integration: Implementation of methods for the numerical computation of integrals in one or two dimensions

## How to compile the program ##

1) Get the code from GitHub: git clone https://github.com/ClaireCp/pcsc.git

2) Move to that directory: cd pcsc

3) If you want to run the file from the command line: 
<br />	mkdir build
<br />	cd build
<br />	cmake ..
<br /> 	make
<br />	./Main   // to run the Main executable
<br />	./Tests  // to run the Tests executable

4) Else open clion and run the code manually


## Typical program execution and usage ##
The source code generates two executables.

### 1) Main ###
The Main.cpp provides an example as how to use the program in order to numerically compute an integral for a given method and a given function.

1) Define function: First, the user has to define the function he wants to compute the integral of as a method taking one or two parameters, for exemple in the Main.cpp file, eg:
* double function(double x) { ... } // for the 1D case
* double function(double x, double y) { ... } // for the 2D case

2) Define and initialize numerical solver: Then in the main function, the user instantiates the numerical solver he wants to use. The numerical solvers are objects and can be instiantiated as:
<br />	MethodName* solver = new MethodName(args);
For the 1D case, the arguments are (in that order):
<br />	n = number of steps
<br />	x0 = initial argument (start of range)
<br />	xf = final argument (end of range)
<br />	t = function to be integrated

For the 2D case, the arguments are (in that order):
<br />	n_x = number of steps in the x direction
<br />	x0 = initial argument for the x direction
<br />	xf = final argument for the x direction
<br />	n_y = number of steps in the y direction
<br />	y0 = initial arguments for the y direction
<br />	yf = final argument for the y direction
<br />	t = 2D function

The check on the arguments is such that if the provided number of steps is inferior or equal to 0, the program stops with an error. Moreover, if the start and the end of the range are inverted, the  program deals with it under the hood by switching both arguments without warning the user.

3) Compute integral: The user can then call the method SolveIntegral() on the numerical solver object to obtain the numerical approximation of the integral:
	double result = solver->SolveIntegral();

4) Deallocate pointer: Don't forget to deallocate the pointer!
<br />	delete(solver);

### 2) Tests ###
The second executable provides a test suite for the program.

This code is open for modification and given the hierarchy and structure of the code, it would be very easy to add more numerical solvers for 1D and 2D cases, as well as considering higher order cases (3D, ...). 

It is always a good idea to provide a test suite, such that in case of modifications and refactoring, tests can be added fast, but most importantly to ensure that new code doesn't cause bugs or causes the program to crash for code that was already implemented and working.


## List of features ##
The program allows for numerical solving of 1D and 2D functions, with the following numerical methods:
<br />	Midpoint
<br />	Trapezoidal
<br />	Cavalieri-Simpson

## List of tests ##
The tests provided in the Tests.cpp file are:
<br />	WrongStepNumber: checks the expected behavior of the program when a negative number of step is given to the constructor of a numerical solver (expected = program exits with 1)
<br />	IntervalTest: when the integration interval is reversed, program should switch the initial and final arguments
<br />	MethodName1D/2DTests: checks the numerical solution obtained from each solver with its analytical solution to ensure that each method computes the correct integral

## Issues and perspectives ##
It would be interesting to add a parser such that a user might input the function and bounds of the integral he wants solved from the command line. The choice of the numerical method could also be done through the command line.

Other numerical solvers or higher dimensions could also be added to the existing code.





