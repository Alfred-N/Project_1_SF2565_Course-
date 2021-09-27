#include "Matrix.h"

//------------------------Constructors-------------------------
Matrix::Matrix(int m) 
{
	_m = m;
	_n = m;
	_2Darr = new double* [m];
	for (unsigned int i = 0; i < m; i++)
	{
		_2Darr[i] = new double [_n];
	}
	this->fillMatrix(0);
}

Matrix::Matrix(int m, int n)
{
	_m = m;
	_n = n;
	_2Darr = new double* [m];
	for (unsigned int i = 0; i < m; i++)
	{
		_2Darr[i] = new double[_n];
	}
	this->fillMatrix(0);
}

Matrix::Matrix(int m, int n, double** other_arr)
{
	_m = m;
	_n = n;
	_2Darr = new double* [m];
	for (unsigned int i = 0; i < m; i++)
	{
		_2Darr[i] = new double[m];
		memcpy(_2Darr[i], other_arr[i], _n * sizeof(double));
	}
}

Matrix::Matrix(const Matrix &other)
	: _m(other._m), _n(other._n)
{
	_2Darr = new double* [_m];
	for (unsigned int i = 0; i < _m; i++)
	{
		_2Darr[i] = new double[_n];
		memcpy(_2Darr[i], other._2Darr[i], _n*sizeof(double));
	}
}

//------------------------Assignment operator -------------------------

/// <summary>
/// 
/// </summary>
/// <param name="other"></param>
/// <returns></returns>
Matrix& Matrix::operator=(const Matrix& other) 
{
	if (this != &other)
	{
		if (_m == other._m && _n == other._n)
		{
			for (unsigned int i = 0; i < _m; i++)
			{
				for (unsigned int j = 0; j < _n; j++)
				{
					_2Darr[i][j] = other._2Darr[i][j];
				}
			}
		}
		else
		{
			//Different sizes, deleting old _2Darr and allocating new _2Darr
			for (int i = 0; i < _m; i++)
			{
				delete[] _2Darr[i];
			}
			delete[] _2Darr;
			//perform deep copy
			this->_m = other._m; this->_n = other._n;
			_2Darr = new double* [_m];
			for (unsigned int i = 0; i < _m; i++)
			{
				_2Darr[i] = new double[_n];
				memcpy(_2Darr[i], other._2Darr[i], _n * sizeof(double));
			}
		}
	}
	return *this;
}

//------------------------Addition/Subtraction-------------------------
Matrix& Matrix::operator+=(const Matrix& other)
{
	this->checkDimsAdd(other);

	for (unsigned int i = 0; i < _m; i++)
	{
		for (unsigned int j = 0; j < _n; j++)
		{
			_2Darr[i][j] += other._2Darr[i][j];
		}
	}
	return *this;
}

Matrix Matrix::operator+(const Matrix& other) const
{
	this->checkDimsAdd(other);

	Matrix temp = Matrix(_m, _n);
	for (unsigned int i = 0; i < _m; i++)
	{
		for (unsigned int j = 0; j < _n; j++)
		{
			temp._2Darr[i][j] = _2Darr[i][j] + other._2Darr[i][j];
		}
	}
	return temp;
}

Matrix& Matrix::operator-=(const Matrix& other)
{
	this->checkDimsAdd(other);

	for (unsigned int i = 0; i < _m; i++)
	{
		for (unsigned int j = 0; j < _n; j++)
		{
			_2Darr[i][j] -= other._2Darr[i][j];
		}
	}
	return *this;
}

Matrix Matrix::operator-(const Matrix& other) const
{
	this->checkDimsAdd(other);

	Matrix temp = Matrix(_m, _n);
	for (unsigned int i = 0; i < _m; i++)
	{
		for (unsigned int j = 0; j < _n; j++)
		{
			temp._2Darr[i][j] = _2Darr[i][j] - other._2Darr[i][j];
		}
	}

	return temp;
}

//------------------------Multiplication-------------------------
Matrix& Matrix::operator*=(const Matrix& other)
{
	this->checkDimsMult(other);
	Matrix temp = Matrix(_m, other._n);

	for (unsigned int i = 0; i < _m; i++)
	{
		for (unsigned int j = 0; j < other._n; j++)
		{
			for (int k = 0; k < _n; k++)
			{
				temp._2Darr[i][j] += _2Darr[i][k] * other._2Darr[k][j];
			}			
		}
	}
	(*this) = temp;
	return *this;
}

Matrix Matrix::operator*(const Matrix& other) const
{
	this->checkDimsMult(other);

	Matrix temp = Matrix(_m, other._n);
	for (unsigned int i = 0; i < _m; i++)
	{
		for (unsigned int j = 0; j < other._n; j++)
		{
			for (int k = 0; k < _n; k++)
			{
				temp._2Darr[i][j] += _2Darr[i][k] * other._2Darr[k][j];
			}
		}
	}
	return temp;
}

Matrix& Matrix::operator*=(const double& scalar)
{
	for (unsigned int i = 0; i < _m; i++)
	{
		for (unsigned int j = 0; j < _n; j++)
		{
			_2Darr[i][j] *= scalar;
		}
	}
	return *this;
}

Matrix Matrix::operator*(const double& scalar) const
{
	Matrix temp = Matrix(_m, _n);
	for (unsigned int i = 0; i < _m; i++)
	{
		for (unsigned int j = 0; j < _m; j++)
		{
			temp._2Darr[i][j] += _2Darr[i][j] * scalar;
		}
	}
	return temp;
}

//------------------------Miscellaneous functions-------------------------
void Matrix::setElement(const int &m, const int &n, const double val)
{
	_2Darr[m][n] = val;
}


void Matrix::printMatrix()
{	
	cout << "[" << flush;
	for (unsigned int i = 0; i < _m; i++)
	{
		cout << "[" << flush;
		for (unsigned int j = 0; j < _n; j++)
		{
			if (j < _n - 1) { cout << _2Darr[i][j] << " ," << flush; }
			else { cout << _2Darr[i][j] << flush; }
		}
		if (i < _m - 1) { cout << "]" << endl; }
		else { cout << "]" << flush; }
	}
	cout << "]" << endl;
}
/// <summary>
/// Set every Matrix element to fillNumber
/// </summary>
/// <param name="int fillNumber"></param>
void Matrix::fillMatrix(double fillNumber)
{
	for (unsigned int i = 0; i < _m; i++)
	{
		for (unsigned int j = 0; j < _n; j++)
		{
			_2Darr[i][j] = fillNumber;
		}
	}
}

/// <summary>
/// Get the transpose of a Matrix
/// </summary>
/// <returns>Matrix object</returns>
Matrix Matrix::transpose()
{
	Matrix temp(_n,_m);
	for (unsigned int i = 0; i < _n; i++)
	{
		for (unsigned int j = 0; j < _m; j++)
		{
			temp._2Darr[i][j] = _2Darr[j][i];
		}
	}
	return temp;
}

Matrix Matrix::identity() const
{
	try
	{
		if (!(*this).isSquare())
		{
			throw std::length_error("Matrix is not square, identity() undefined. Exiting ...");
		}
	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
		exit(EXIT_FAILURE);
	}
	Matrix temp(_m);
	for (int i = 0; i < _m; i++)
	{
		temp._2Darr[i][i] = 1;
	}
	return temp;
}




/// <summary>
/// Frobenius norm of a (real) Matrix object
/// </summary>
/// <returns>double scalar</returns>
double Matrix::norm() const
{
	Matrix transp = *this;
	transp = transp.transpose();
	Matrix prod = transp * (*this);
	double trace = 0;
	for (unsigned int i = 0; i < _n; i++)
	{
		trace += prod._2Darr[i][i];
	}
	return sqrt(trace);
}


/// <summary>
/// Helper function to check for dimension mismatch when adding Matrix objects
/// </summary>
/// <param name="other">Matrix object to compare to</param>
void Matrix::checkDimsAdd(const Matrix& other) const
{
	try
	{
		if (_m != other._m || _n != other._n)
		{
			throw std::length_error("Mismatched matrix dimensions, cannot add");
		}
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
		exit(EXIT_FAILURE);
	}
}
/// <summary>
/// Helper function to check for dimension mismatch when multiplying Matrix objects
/// </summary>
/// <param name="other">Matrix object to compare to</param>
void Matrix::checkDimsMult(const Matrix& other) const
{
	try
	{
		if (_n != other._m)
		{
			throw std::length_error("Mismatched matrix dimensions, cannot multiply");
		}
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
		exit(EXIT_FAILURE);
	}
}

const bool Matrix::isSquare() const
{
	if (_m==_n)
	{
		return true;
	}
	else
	{
		return false;
	}
}


/// <summary>
/// Non-member function that allows multiplying a Matrix object from the left with a double
/// </summary>
/// <param name="scalar">double to multiply</param>
/// <param name="matrix">Matrix to multiply</param>
/// <returns>Matrix object</returns>
Matrix operator*(double scalar, const Matrix& matrix)
{
	Matrix temp = Matrix(matrix);
	temp *= scalar;
	return temp;
}
