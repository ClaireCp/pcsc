/*
 * Tools.cpp
 *
 *  Created on: November 25, 2018
 *      Author: Claire Capelo <claire.capelo@epfl.ch>
 */

#ifndef TOOLS_HPP
#define TOOLS_HPP

/** Tool functions to perform checks on the arguments of numerical solvers.
 */

/** Checks that the number of steps is strictly superior to zero. If not interrupts the program.
 * @param n number of steps
 */
void checkNumberOfSteps(int n);

/** Checks if the initial argument is smaller than the final argument. If not, it switches them.
 * @param x0 initial argument of the interval
 * @param xf final argument of the interval
 */
void checkInterval(double* x0, double* xf);

#endif // TOOLS_HPP
