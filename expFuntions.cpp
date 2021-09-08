#include "Header.h"

double myExp(double x_in, double, tol, int fac, double prev)
{
	fac *= fac;

	if (idx == n) { return prev + x_in *fac; } //return the last term

	else if (idx == 0) // return the value of the polynomial as a function of the next parenthesis
	{
		if (useMod) { x_in = fmod(x_in, 2 * M_PI); }
		return x_in * sinTaylor(x_in, n, idx + 1, prev);
	}
	else  //return the value of the current parenthesis as a function of the next parenthesis
	{
		double currCoeff = getSinCoeff(idx, prev);
		return prev + x_in * x_in * sinTaylor(x_in, n, idx + 1, currCoeff);
	}



//double getSinCoeff(int n, double prev_coeff)
//{
//	assert(n >= 0 && "n must be geq than 0");
//	if (n == 0) { return 1; }
//	else { return (double)-1 / ((2 * n + 1) * (2 * n)) * prev_coeff; }
//}
