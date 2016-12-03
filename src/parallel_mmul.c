#include <stdio.h>

#include "include/Matrix.h"

int parallelMatrixMul(Matrix a, Matrix b, Matrix *result)
{
    if (a.columnCount != b.rowCount) {
        printf("Error: wrong matrix dimensions.\n");
        return 1;
    }

    #pragma omp parallel for collapse(2)
    for (int i = 0; i < a.rowCount; ++i) {
        for (int k = 0; k < b.columnCount; ++k) {
            for (int j = 0; j < a.columnCount; ++j) {
                addToElementValue(result, i, k,
                        getElementValue(a, i, j) * getElementValue(b, j, k));
            }
        }
    }

    return 0;
}
