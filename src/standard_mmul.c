#include "Matrix.h"
#include "matrixmultiplication.h"

Matrix standardMatrixMul(Matrix a, Matrix b)
{
    if (a.columnCount != b.rowCount) {
        return newMatrix(0, 0);
    }

    Matrix result = newMatrix(a.rowCount, b.columnCount);
    double sum = 0.0;
    for (int i = 0; i < a.rowCount; ++i) {
        for (int k = 0; k < b.columnCount; ++k) {
            sum = 0.0;
            for (int j = 0; j < a.columnCount; ++j) {
                sum += getElementValue(a, i, j) * getElementValue(b, j, k);
            }
            setElementValue(&result, i, k, sum);
        }
    }
    return result;
}
