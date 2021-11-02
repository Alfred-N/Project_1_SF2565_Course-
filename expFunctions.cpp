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
/// <summary>
/// Calculates the matrix exponential using the power series definition.///
/// </summary>
/// <param name="A">The matrix to evaluate the exponential on</param>
/// <param name="tol">Tolerance as in the maximum allowed error of the norm</param>
/// <returns></returns>
Matrix myExp(const Matrix& A, double tol)
{
	try
	{
		if (!A.isSquare())
		{
			throw std::length_error("Matrix is not square, exp() undefined. Exiting ...");
		}
	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
		exit(EXIT_FAILURE);
	}
	//--------------------------------------------------------------
	Matrix A_pow = A.identity();
	Matrix expA = A_pow;
	Matrix expA_next = expA * INFINITY;
	Matrix diff(A);
	double error = INFINITY;
	int fac = 1;
	int i = 1;
	const int maxIt = 100;
	while (error>tol)
	{
		A_pow *= A;
		expA += A_pow * (1.0 / fac);
		i += 1;
		fac *= i;
		expA_next = (A_pow * A) * (1.0 / fac);
		diff = expA_next - expA;
		error = diff.norm();

		//expA.printMatrix();
		if (i > maxIt)
		{
			printf("%s%d%s", "Warning: max iterations of ", maxIt, " reached. Specified tol not guaranteed. Try a larger tol \n");
			break;
		}
		
	}
	cout << "It: = " << i << endl;
	return expA;
}



//printf("%d%s %d %s", i, "! = ", fac, "\n");
//printf("%s %d %s", "x power = ", i, "\n");