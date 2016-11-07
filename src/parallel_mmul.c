#include <omp.h>
#include <stdio.h>

#include "include/Matrix.h"

int parallelMatrixMul(Matrix a, Matrix b, Matrix *result)
{
    if (a.columnCount != b.rowCount) {
        printf("Error: wrong matrix dimensions.\n");
        return 1;
    }

    // do the parallel execution
    return 0;
}
