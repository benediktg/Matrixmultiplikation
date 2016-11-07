#include <stdio.h>

#include "include/Matrix.h"

int main(void)
{
    float d1[] = {
        2, 0, 0, 0,
        0, 2, 0, 0,
        0, 0, 3, 0,
        1, 1, 1, 1,
    };
    float d2[] = {
        3, 0, 0, 0,
        0, 2, 0, 0,
        0, 0, 2, 0,
        1, 1, 1, 1,
    };
    Matrix m1 = {4, 4, d1};
    Matrix m2 = {4, 4, d2};
    prettyPrint(m1);
    prettyPrint(m2);

    Matrix result = allocMatrix(m1, m2);
    standardMatrixMul(m1, m2, &result);
    prettyPrint(result);
    freeMatrix(&result);
    return 0;
}
