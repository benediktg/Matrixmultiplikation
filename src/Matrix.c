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

int freeMatrix(Matrix* matrix)
{
    free(matrix->data);
    matrix->data = NULL;
    return 0;
}

bool isNullMatrix(Matrix matrix)
{
    if ((matrix.rowCount == 0 )
            || (matrix.columnCount == 0)
            || (matrix.data == NULL)) {
        return true;
    }
    return false;
}

bool isSquareMatrix(Matrix matrix)
{
    if (matrix.rowCount == matrix.columnCount) {
        return true;
    }
    return false;
}

bool areEqualMatrices(Matrix a, Matrix b)
{
    if (a.rowCount != b.rowCount || a.columnCount != b.columnCount) {
        return false;
    }
    float compare;
    for (int i = 0; i < a.rowCount; ++i) {
        for (int j = 0; j < a.columnCount; ++j) {
            compare = getElementValue(a, i, j) - getElementValue(b, i, j);
            if (compare > EPSILON || compare < -EPSILON) {
                return false;
            }
        }
    }
    return true;
}


float getElementValue(Matrix matrix, int i, int j)
{
    if (isNullMatrix(matrix)) {
        printf("Error: null matrix.\n");
    } else if ((i < 0) || (j < 0)) {
        printf("Error: negative index.\n");
    } else if ((i >= matrix.rowCount) || (j >= matrix.columnCount)) {
        printf("Error: too big index.\n");
    }
    return matrix.data[matrix.columnCount * i + j];
}

void setElementValue(Matrix *matrix, int i, int j, float value)
{
    if (isNullMatrix(*matrix)) {
        printf("Error: null matrix.\n");
    } else if ((i < 0) || (j < 0)) {
        printf("Error: negative index.\n");
    } else if ((i >= matrix->rowCount) || (j >= matrix->columnCount)) {
        printf("Error: too big index\n");
    }
    matrix->data[matrix->columnCount * i + j] = value;
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
