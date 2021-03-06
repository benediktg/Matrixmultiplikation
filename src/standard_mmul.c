#include <stdio.h>

#include "include/Matrix.h"

int standardMatrixMul(Matrix a, Matrix b, Matrix *result)
{
    if (a.columnCount != b.rowCount) {
        printf("Error: wrong matrix dimensions.\n");
        return 1;
    }

    for (int i = 0; i < a.rowCount; ++i) {
        for (int k = 0; k < b.columnCount; ++k) {
            float sum = 0.0f;
            for (int j = 0; j < a.columnCount; ++j) {
                sum += getElementValue(a, i, j) * getElementValue(b, j, k);
            }
            setElementValue(result, i, k, sum);
        }
    }
    return 0;
}
