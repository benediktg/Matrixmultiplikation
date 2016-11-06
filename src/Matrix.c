#include <stdio.h>
#include <stdlib.h>

#include "Matrix.h"

Matrix newMatrix(int rowCount, int columnCount)
{
    if ((rowCount < 0) || (columnCount < 0)) {
        printf("Error: negative matrix size.\n");
        rowCount = 0;
        columnCount = 0;
    }
    double *array = malloc(rowCount * columnCount * sizeof *array);
    Matrix result = {rowCount, columnCount, array};
    return result;
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

bool isSymmetricMatrix(Matrix matrix)
{
    if (matrix.rowCount == matrix.columnCount) {
        return true;
    }
    return false;
}

double getElementValue(Matrix matrix, int i, int j)
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

void setElementValue(Matrix *matrix, int i, int j, double value)
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

void prettyPrint(Matrix matrix)
{
    if (isNullMatrix(matrix)) {
        printf("[ - ]\n\n");
        return;
    }
    for (int i = 0; i < matrix.rowCount; ++i) {
        printf("[ ");
        for (int j = 0; j < matrix.columnCount; ++j) {
            printf("%.1lf ", getElementValue(matrix, i, j));
        }
        printf("]\n");
    }
    printf("\n");
}
