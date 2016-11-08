#include <stdio.h>

#include "include/Matrix.h"

int optimizedMatrixMul(Matrix a, Matrix b, Matrix *result, int termination)
{
    if (a.columnCount != b.rowCount) {
        printf("Error: wrong matrix dimensions.\n");
        return 1;
    } else if (!(isSquareMatrix(a))
            || !(isSquareMatrix(b))) {
        printf("Error: please provide symmetric matrices.\n");
        return 2;
    }

    // do the optimized calculation
    return 0;
}
