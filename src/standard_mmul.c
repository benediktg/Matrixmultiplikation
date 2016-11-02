#include "include/Matrix.h"

#include <stddef.h>
#include <stdlib.h>

Matrix standardMatrixMul(Matrix a, Matrix b)
{
    if (a.columns != b.rows) {
        return createMatrix(0, 0);
    }

    Matrix result = createMatrix(a.rows, b.columns);
    for (int i = 0; i < a.rows; ++i) {
        for (int k = 0; k < b.columns; ++k) {
            double value = 0.0;
            for (int j = 0; j < a.columns; ++j) {
                value += getElementValue(a, i, j) * getElementValue(b, j, k);
            }
            setElementValue(&result, i, k, value);
        }
    }
    return result;
}
