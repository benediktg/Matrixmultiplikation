#ifndef MATRIX_H
#define MATRIX_H

#include <stdlib.h>

typedef struct Matrix
{
    int rowCount;
    int columnCount;
    double *data;
} Matrix;

Matrix createMatrix(int rowCount, int columnCount)
{
    Matrix result;
    result.rowCount = rowCount;
    result.columnCount = columnCount;
    result.data = malloc(rowCount * columnCount * sizeof(double));
    return result;
}

double getElementValue(Matrix matrix, int i, int j)
{
    return matrix.data[matrix.columnCount * i + j];
}

void setElementValue(Matrix *matrix, int i, int j, double value)
{
    matrix->data[matrix->columnCount * i + j] = value;
}

#endif // MATRIX_H
