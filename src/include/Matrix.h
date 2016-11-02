#ifndef MATRIX_H
#define MATRIX_H

#include <stddef.h>
#include <stdlib.h>

typedef struct Matrix
{
    size_t rows;
    size_t columns;
    double *data;
} Matrix;

Matrix createMatrix(size_t rowCount, size_t columnCount)
{
    Matrix result;
    result.rows = rowCount;
    result.columns = columnCount;
    result.data = malloc(rowCount * columnCount * sizeof(double));
    return result;
}

double getElementValue(Matrix matrix, int i, int j)
{
    return matrix.data[matrix.rows * i + j];
}

void setElementValue(Matrix *matrix, int i, int j, double value)
{
    matrix->data[matrix->rows * i + j] = value;
}

#endif // MATRIX_H
