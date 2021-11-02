#pragma once
#include <cmath>
#include <iostream>
#include "Matrix.h"
#include "FortranMatHeader.h"

using namespace std;
#include "r8lib.h"
#include "r8mat_expm1.h"

/// <summary> Implementation of exp() using Taylor expansion </summary>
/// <param name="x_in"> (double) The point of evaluation </param> 
/// <param name="tol"> (double) specified tolerance (default = 1e-8) </param> 
/// <returns> exp(x_in) (double)
/// </returns>
double myExp(double, double tol = 1e-8);
Matrix myExp(const Matrix&, double tol = 1e-3);

/// <summary>
/// Script for testing the basic arithmetic functions of the Matrix class
/// </summary>
void testMatrixArithmetic();


