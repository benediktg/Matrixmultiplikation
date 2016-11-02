#include "include/Matrix.h"

#include <stddef.h>
#include <stdlib.h>

Matrix standardMatrixMul(Matrix a, Matrix b)
{
    if (a.columnCount != b.rowCount) {
        return createMatrix(0, 0);
    }

    Matrix result = createMatrix(a.rowCount, b.columnCount);
    for (int i = 0; i < a.rowCount; ++i) {
        for (int k = 0; k < b.columnCount; ++k) {
            double value = 0.0;
            for (int j = 0; j < a.columnCount; ++j) {
                value += getElementValue(a, i, j) * getElementValue(b, j, k);
            }
            setElementValue(&result, i, k, value);
        }
    }
    return result;
}
