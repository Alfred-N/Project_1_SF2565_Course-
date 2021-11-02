// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Header.h"

int main()
{
    ////Scalar test
    //const double* scalars = new double[5]{ -2,-0.5, 0, 0.5, 5 };
    ////const double x = -1;
    //for (unsigned int i = 0; i < 5; i++)
    //{
    //    double x = scalars[i];
    //    printf("%s%f%s %.10f%s", "myExp(", x, ") \t= \t", myExp(x, 1e-10), "\n");
    //    printf("%s%f%s %.10f%s", "std::exp(", x, ") \t= \t", exp(x), "\n");
    //}
    

    //Matrix tests
    Matrix A = Matrix(2).identity();
    Matrix expA = myExp(A); expA.printMatrix(); //Exp of the 2x2 identity matrix using my exp function

    double* resultA = r8mat_expm1(2, new double [] {1, 0, 0, 1});
    FortranMatrix result_mat_A(2, resultA); result_mat_A.printMatrix(); //Exp of the 2x2 identity using r8mat_expm1

    //Random-y matrix
    Matrix B(3, 3, new double* [] {new double[] {-0.123, 1.7, 0}, new double[] {0.3, 0.2, 0}, new double[] {0, 0.01, 0}});
    Matrix expB = myExp(B); expB.printMatrix();

    double* resultB = r8mat_expm1(3, new double [] {-0.123, 0.3, 0, 1.7, 0.2, 0.01, 0, 0, 0});
    FortranMatrix result_mat_B(3, resultB); result_mat_B.printMatrix(); 

    //Large values - overflow issues
    Matrix C(3, 3, new double* [] {new double[] {6, 6, 6}, new double[] {5, 5, 5}, new double[] {2, 2, 2}});
    Matrix expC = myExp(C); expC.printMatrix(); 

    double* resultC = r8mat_expm1(3, new double [] {6, 5, 2, 6, 5, 2, 6, 5, 2});
    FortranMatrix result_mat_C(3, resultC); result_mat_C.printMatrix(); 


    
    //testMatrixArithmetic();

    return EXIT_SUCCESS;
}
