#include <stdio.h>

#include "Matrix.h"

int main(void)
{
    double d1[] = {
        2, 0, 0,
        0, 2, 0,
        0, 0, 3,
    };
    Matrix m1 = newMatrix(3, 3);
    m1.data = d1;
    double d2[] = {
        3, 0, 0,
        0, 2, 0,
        0, 0, 2,
    };
    Matrix m2 = newMatrix(3, 3);
    m2.data = d2;
    prettyPrint(m1);
    prettyPrint(m2);

    Matrix result = standardMatrixMul(m1, m2);
    prettyPrint(result);
    return 0;
}
