#include "Header.h"

double myExp(double x_in, double tol)
{
	double sum = 1.0;
	double next_term = INFINITY;
	int fac = 1;
	double x_pow = 1;
	const int maxIt = 50;
	int i = 1;
	while (abs(next_term)>tol)
	{
		x_pow *= x_in;
		sum += x_pow / fac;
		i += 1;
		fac *= i;
		next_term = x_pow * x_in / fac;

		if (i>maxIt)
		{
			printf("%s%d%s", "Warning: max iterations of ", maxIt, " reached. Specified tol not guaranteed. Try a larger tol \n");
			break;			
		}
	}
	return sum + next_term;
}

//printf("%d%s %d %s", i, "! = ", fac, "\n");
//printf("%s %d %s", "x power = ", i, "\n");