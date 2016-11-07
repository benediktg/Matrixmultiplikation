#include <stdio.h>

#include "include/Matrix.h"

int main(void)
{
    float d1[] = {
        2, 0, 0, 0,
        0, 2, 0, 0,
        0, 0, 3, 0,
    };
    Matrix m1 = newMatrix(3, 4);
    m1.data = d1;
    float d2[] = {
        3, 0, 0, 0,
        0, 2, 0, 0,
        0, 0, 2, 0,
    };
    Matrix m2 = newMatrix(3, 4);
    m2.data = d2;
    prettyPrint(m1);
    prettyPrint(m2);

    Matrix result = standardMatrixMul(m1, m2);
    prettyPrint(result);
    return 0;
}
