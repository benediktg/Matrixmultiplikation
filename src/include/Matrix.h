#ifndef MATRIX_H
#define MATRIX_H

#include <stdbool.h>

typedef struct Matrix {
    int rowCount;
    int columnCount;
    double *data;
} Matrix;

/**
 * Constructs a Matrix instance and returns it.
 */
Matrix newMatrix(int rowCount, int columnCount);

/**
 * Checks if the matrix is similar to a null object.
 */
bool isNullMatrix(Matrix m);

/**
 * Retrieves a value of a matrix element.
 */
double getElementValue(Matrix matrix, int i, int j);

/**
 * Sets a value of a matrix element.
 */
void setElementValue(Matrix *matrix, int i, int j, double value);

#endif // MATRIX_H
