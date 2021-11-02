#include "FortranMatHeader.h"

FortranMatrix::FortranMatrix(int m)
{
	_m = m;
	_n = m;
	_C_mat = new double [m*m];
	this->fillMatrix(0);
}
FortranMatrix::FortranMatrix(int m, double* other_arr)
{
	_m = m;
	_n = m;
	_C_mat = new double[_m * _m];
	memcpy(_C_mat, other_arr, _m * _m * sizeof(double));
}

void FortranMatrix::fillMatrix(double fillNumber)
{
	for (unsigned int i = 0; i < _m; i++)
	{
		for (unsigned int j = 0; j < _n; j++)
		{
			_C_mat[i+_n*j] = fillNumber;
		}
	}
}

void FortranMatrix::printMatrix()
{
	cout << "[" << flush;
	for (unsigned int i = 0; i < _m; i++)
	{
		cout << "[" << flush;
		for (unsigned int j = 0; j < _n; j++)
		{
			if (j < _n - 1) { cout << _C_mat[i + _n * j] << " ," << flush; }
			else { cout << _C_mat[i + _n * j] << flush; }
		}
		if (i < _m - 1) { cout << "]" << endl; }
		else { cout << "]" << flush; }
	}
	cout << "]" << endl;
}

double* FortranMatrix::getArr()
{
	double* arr = this->_C_mat;
	return arr;
}
