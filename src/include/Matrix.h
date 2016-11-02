#ifndef MATRIX_H
#define MATRIX_H

#include <stddef.h>
#include <stdlib.h>

typedef struct Matrix
{
    size_t rowCount;
    size_t columnCount;
    double *data;
} Matrix;

Matrix createMatrix(size_t rowCount, size_t columnCount)
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
