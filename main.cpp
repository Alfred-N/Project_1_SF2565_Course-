// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Header.h"

int main()
{
    /*const double x = -1;
    printf("%s%f%s %f%s", "myExp(", x, ") \t= \t", myExp(x, 1e-8), "\n");
    printf("%s%f%s %f%s", "std::exp(", x, ") \t= \t", exp(x), "\n");*/
    Matrix a(2, 2, new double* [] {new double[] {2, 0}, new double[] {0, 2}});
    Matrix expA = myExp(a); expA.printMatrix();
    
    
    //testMatrixArithmetic();

    return EXIT_SUCCESS;
}
