#include <stdio.h>

#include "include/Matrix.h"

#include "example_matrices.h"

int main(void)
{
    Matrix m1 = {MATRIX_SIZE, MATRIX_SIZE, MATRIX_1};
    Matrix m2 = {MATRIX_SIZE, MATRIX_SIZE, MATRIX_2};

    Matrix result = allocMatrix(m1, m2);
    standardMatrixMul(m1, m2, &result);
    freeMatrix(&result);
    return 0;
}
