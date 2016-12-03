#include <stdio.h>
#include <stdlib.h>

#include "include/Matrix.h"

Matrix allocMatrix(Matrix a, Matrix b)
{
    int rowCount = a.rowCount;
    int columnCount = b.columnCount;
    if (rowCount < 0 && columnCount < 0) {
        printf("Error: negative matrix size.\n");
    }
    float *data = calloc(rowCount * columnCount, sizeof *data);
    Matrix matrix = {rowCount, columnCount, data};
    return matrix;
}

bool areEqualMatrices(Matrix a, Matrix b)
{
    if (a.rowCount != b.rowCount || a.columnCount != b.columnCount) {
        return false;
    }
    for (int i = 0; i < a.rowCount; ++i) {
        for (int j = 0; j < a.columnCount; ++j) {
            if (!equalsFloat(
                    getElementValue(a, i, j), getElementValue(b, i, j))) {
                return false;
            }
        }
    }
    return true;
}

int prettyPrint(Matrix matrix)
{
    if (isNullMatrix(matrix)) {
        printf("[ - ]\n\n");
        return 1;
    }
    for (int i = 0; i < matrix.rowCount; ++i) {
        printf("[ ");
        for (int j = 0; j < matrix.columnCount; ++j) {
            printf("%.1f ", getElementValue(matrix, i, j));
        }
        printf("]\n");
    }
    printf("\n");
    return 0;
}
