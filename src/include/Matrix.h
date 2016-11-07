#ifndef MATRIX_H
#define MATRIX_H

#include <stdbool.h>

/**
 * Represents a matrix.
 */
typedef struct Matrix {
    /** count of rows */
    int rowCount;
    /** count of columns */
    int columnCount;
    /** the actual matrix which is supposed to have a size of
     * count of rows times columns */
    float *data;
} Matrix;

/*****************************
 * Access and help functions *
 *****************************/

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
 *
 * @param matrix the matrix instance (dimension M × N)
 * @param i the row number (must be in the interval 0..M-1)
 * @param j the column number (must be in the interval 0..N-1)
 * @returns the value of the given element
 */
float getElementValue(Matrix matrix, int i, int j);

/**
 * Sets a value of a matrix element.
 *
 * @param matrix the matrix instance (dimension M × N)
 * @param i the row number (must be in the interval 0..M–1)
 * @param j the column number (must be in the interval 0..N–1)
 * @param value the value to set
 */
void setElementValue(Matrix *matrix, int i, int j, float value);

/**
 * Prints a representation of the matrix to stdout.
 */
void prettyPrint(Matrix matrix);

/*************************
 * Matrix multiplication *
 *************************/

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
