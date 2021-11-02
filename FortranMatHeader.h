#pragma once
using namespace std;
#include <iostream>
class FortranMatrix 
{
private:
	double* _C_mat;
	int _m, _n;
public:
	//Constructors
	FortranMatrix(int);
	FortranMatrix(int, double*);
	void fillMatrix(double fillNumber);
	void printMatrix();
	double* getArr();
};
