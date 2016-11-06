#include <stdio.h>

#include "include/Matrix.h"

Matrix optimizedMatrixMul(Matrix a, Matrix b, int termination)
{
    if (a.columnCount != b.rowCount) {
        printf("Error: wrong matrix dimensions.\n");
        return newMatrix(0, 0);
    } else if (!(isSymmetricMatrix(a))
            || !(isSymmetricMatrix(b))) {
        printf("Error: please provide symmetric matrices.\n");
        return newMatrix(0, 0);
    }

    Matrix result = newMatrix(a.rowCount, b.columnCount);
    // do the optimized calculation
    return result;
}
