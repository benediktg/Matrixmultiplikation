#include <stdio.h>

#include "include/Matrix.h"

Matrix optimizedMatrixMul(Matrix a, Matrix b, int termination)
{
    if ((a.columnCount != b.rowCount)
            || !(isSymmetricMatrix(a))
            || !(isSymmetricMatrix(b))) {
        printf("Error: wrong matrix dimensions.\n");
        return newMatrix(0, 0);
    }

    Matrix result = newMatrix(a.rowCount, b.columnCount);
    // do the optimized calculation
    return result;
}
