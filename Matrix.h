using namespace std;
#include <iostream>
class Matrix {
private:
	double** _2Darr;
	int _m;
public:
	Matrix(int m);
	Matrix(const Matrix&);
	/*Matrix& operator=(const Matrix&);
	Matrix& operator+=(const Matrix&);
	Matrix& operator*=(const Matrix&);
	Matrix& operator*=(const double);
	double norm() const;*/
	void setElement(const int &m, const int &n, double val);
	void printMatrix();
	void fillMatrix(double fillNumber);
};