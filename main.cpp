// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Header.h"

int main()
{
    /*const double x = -1;
    printf("%s%f%s %f%s", "myExp(", x, ") \t= \t", myExp(x, 1e-8), "\n");
    printf("%s%f%s %f%s", "std::exp(", x, ") \t= \t", exp(x), "\n");*/

    Matrix a = Matrix(3);
    a.fillMatrix(0);
    
    Matrix b = a;
    b.setElement(1, 1, 5.0);
    a.printMatrix();
    b.printMatrix();
    
    return EXIT_SUCCESS;
}


