#pragma once
#include <cmath>
#include <iostream>
#include "Matrix.h"
using namespace std;

/// <summary> Implementation of exp() using Taylor expansion </summary>
/// <param name="x_in"> (double) The point of evaluation </param> 
/// <param name="tol"> (double) specified tolerance (default = 1e-8) </param> 
/// <returns> exp(x_in) (double)
/// </returns>
double myExp(double x_in, double tol = 1e-8);



