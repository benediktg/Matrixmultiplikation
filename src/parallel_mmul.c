#include <omp.h>
#include <stdio.h>

#include "include/Matrix.h"

Matrix parallelMatrixMul(Matrix a, Matrix b)
{
    if (a.columnCount != b.rowCount) {
        printf("Error: wrong matrix dimensions.\n");
        return newMatrix(0, 0);
    }

    Matrix result = newMatrix(a.rowCount, b.columnCount);
    // do the parallel execution
    return result;
}
