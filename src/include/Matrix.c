#include "Matrix.h"

#include <stdio.h>

Matrix newMatrix(int rowCount, int columnCount)
{
    if ((rowCount < 0) || (columnCount < 0)) {
        printf("Error: negative matrix size\n");
        rowCount = 0;
        columnCount = 0;
    }
    double array[rowCount * columnCount];
    Matrix result = {rowCount, columnCount, array};
    return result;
}

bool isNullMatrix(Matrix m)
{
    if (m.rowCount == 0 && m.columnCount == 0 && m.data == NULL) {
        return true;
    }
    return false;
}

double getElementValue(Matrix matrix, int i, int j)
{
    if ((i < 0) || (j < 0)) {
        printf("Error: negative index\n");
    } else if ((i >= matrix.rowCount) || (j >= matrix.columnCount)) {
        printf("Error: too big index\n");
    } else if (isNullMatrix(matrix)) {
        printf("Error: null matrix\n");
    }
    return matrix.data[matrix.columnCount * i + j];
}

void setElementValue(Matrix *matrix, int i, int j, double value)
{
    if (matrix == NULL) {
        printf("Error: null matrix\n");
    } else if ((i < 0) || (j < 0)) {
        printf("Error: negative index\n");
    } else if ((i >= matrix->rowCount) || (j >= matrix->columnCount)) {
        printf("Error: too big index\n");
    }
    matrix->data[matrix->columnCount * i + j] = value;
}

void prettyPrint(Matrix matrix)
{
}
