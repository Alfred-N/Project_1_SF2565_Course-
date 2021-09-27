using namespace std;
#include <iostream>

/// <summary>
/// Class that implements 2D matrix objects with linear algebra arithmetic.
/// </summary>
class Matrix {
private:
	double** _2Darr;
	int _m, _n;
	void checkDimsAdd(const Matrix&) const;
	void checkDimsMult(const Matrix&) const;
public:
	//Constructors
	Matrix(int);
	Matrix(int, int);
	Matrix(int, int, double**);
	Matrix(const Matrix&);
	//Arithmetic
	Matrix& operator=(const Matrix&);
	Matrix& operator+=(const Matrix&);
	Matrix operator+(const Matrix&) const;
	Matrix& operator-=(const Matrix&);
	Matrix operator-(const Matrix&) const;
	Matrix& operator*=(const Matrix&);
	Matrix operator*(const Matrix&) const;
	Matrix& operator*=(const double&);
	Matrix operator*(const double&) const;
	//Misc.
	Matrix transpose();
	Matrix identity() const;

	double norm() const;
	void setElement(const int &m, const int &n, const double);
	void printMatrix();
	void fillMatrix(double fillNumber);
	const bool isSquare() const;
};

Matrix operator*(double, const Matrix&);
