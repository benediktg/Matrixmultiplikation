#include "Matrix.h"
#include "matrixmultiplication.h"

#include <omp.h>

Matrix parallelMatrixMul(Matrix a, Matrix b)
{
    if (a.columnCount != b.rowCount) {
        return newMatrix(0, 0);
    }

    Matrix result = newMatrix(a.rowCount, b.columnCount);
    // do the parallel execution
    return result;
}
