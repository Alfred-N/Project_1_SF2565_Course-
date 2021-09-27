#include "Header.h"


void testMatrixArithmetic()
{
    Matrix a(3);
    a.fillMatrix(0);

    Matrix b = a; //create new matrix b using copy constructor
    b.setElement(1, 1, 5.0);
    a.printMatrix();
    b.printMatrix();
    Matrix c(2), e(2), f(2);
    c = b; //copy assignment operator
    c.printMatrix();

    e.fillMatrix(3);
    f.fillMatrix(7);
    e += f; //+= operator 
    e.printMatrix();
    e -= f; //-= operator 
    e.printMatrix();

    c = e + f; //+ operator
    c.printMatrix();

    c = e - f; //- operator
    c.printMatrix();

    Matrix I(2); I.setElement(0, 0, 1.0); I.setElement(1, 1, 1.0);
    c *= I; //*= operator 
    c.printMatrix();

    c = c * I; //* operator 
    c.printMatrix();

    c *= 2; //*= float operator 
    c.printMatrix();

    c = c * 2; //* float operator
    c.printMatrix();

    c = 2 * c; //* float non-member operator
    c.printMatrix();

    Matrix g(7, 2); g.fillMatrix(5); // non-square matrix
    Matrix vec(2, 1); vec.setElement(0, 0, 1);
    Matrix prod = g * vec; //* for non-square matrices
    prod.printMatrix();

    Matrix h(2, 7); h.fillMatrix(1);
    Matrix prod2 = g * h;
    prod2.printMatrix();

    // matrix transpose function
    Matrix g_t = g.transpose();
    g_t.printMatrix();

    Matrix j(2); j.fillMatrix(3);
    j.printMatrix();
    printf("%f", j.norm());
}