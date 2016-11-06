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
bool isNullMatrix(Matrix matrix);

/**
 * Checks if the matrix is symmetric.
 */
bool isSymmetricMatrix(Matrix matrix);

/**
 * Retrieves a value of a matrix element.
 */
double getElementValue(Matrix matrix, int i, int j);

/**
 * Sets a value of a matrix element.
 */
void setElementValue(Matrix *matrix, int i, int j, double value);

/**
 * Prints a representation of the matrix to stdout.
 */
void prettyPrint(Matrix matrix);

/*************************
 * Matrix multiplication *
 ************************/

/**
 * Naive implementation of a matrix multiplication
 */
Matrix standardMatrixMul(Matrix a, Matrix b);

/**
 * Cache optimized implemetation of a matrix multiplication
 */
Matrix optimizedMatrixMul(Matrix a, Matrix b, int termination);

/**
 * Parallel implementation of a matrix multiplication
 */
Matrix parallelMatrixMul(Matrix a, Matrix b);

#endif // MATRIX_H
