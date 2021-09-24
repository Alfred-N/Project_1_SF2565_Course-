#include "Matrix.h"

//constructor
Matrix::Matrix(int m) 
{
	_m = m;
	_2Darr = new double* [m];
	for (int i = 0; i < m; i++)
	{
		_2Darr[i] = new double [m];
	}
}

Matrix::Matrix(const Matrix &other)
	: _m(other._m)
{
	_2Darr = new double* [_m];
	for (int i = 0; i < _m; i++)
	{
		_2Darr[i] = new double[_m];
		memcpy(_2Darr[i], other._2Darr[i], _m*sizeof(double));
	}
	}
	


void Matrix::setElement(const int &m, const int &n, double val)
{
	_2Darr[m][n] = val;
}


void Matrix::printMatrix()
{	
	cout << "[" << flush;
	for (size_t i = 0; i < _m; i++)
	{
		cout << "[" << flush;
		for (size_t j = 0; j < _m; j++)
		{
			if (j < _m - 1) { cout << _2Darr[i][j] << " ," << flush; }
			else { cout << _2Darr[i][j] << flush; }
		}
		if (i < _m - 1) { cout << "]" << endl; }
		else { cout << "]" << flush; }
	}
	cout << "]" << endl;
}

void Matrix::fillMatrix(double fillNumber)
{
	for (size_t i = 0; i < _m; i++)
	{
		for (size_t j = 0; j < _m; j++)
		{
			_2Darr[i][j] = fillNumber;
		}
	}
}

