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
 * Allocates space for the result of a matrix multiplication.
 */
Matrix allocMatrix(Matrix a, Matrix b);

/**
 * Frees up the space of the matrix data.
 */
int freeMatrix(Matrix *matrix);

/**
 * Checks if the matrix is similar to a null object.
 */
bool isNullMatrix(Matrix matrix);

/**
 * Checks if the matrix is symmetric.
 */
bool isSquareMatrix(Matrix matrix);

/**
 * Checks if the values and dimensions of matrices a and b are equal.
 */
bool areEqualMatrices(Matrix a, Matrix b);

inline bool equalsFloat(float a, float b) {
    const float EPSILON = 0.000001f;
    return ((a - b) < EPSILON && (a - b) > -EPSILON);
}

/**
 * Retrieves a value of a matrix element.
 *
 * @param matrix the matrix instance (dimension M × N)
 * @param i the row number (must be in the interval 0..M-1)
 * @param j the column number (must be in the interval 0..N-1)
 * @returns the value of the given element
 */
inline float getElementValue(Matrix matrix, int i, int j)
{
    return matrix.data[matrix.columnCount * i + j];
}

/**
 * Sets a value of a matrix element.
 *
 * @param matrix the matrix instance (dimension M × N)
 * @param i the row number (must be in the interval 0..M–1)
 * @param j the column number (must be in the interval 0..N–1)
 * @param value the value to set
 */
inline void setElementValue(Matrix *matrix, int i, int j, float value)
{
    matrix->data[matrix->columnCount * i + j] = value;
}

/**
 * Prints a representation of the matrix to stdout.
 */
int prettyPrint(Matrix matrix);

/*************************
 * Matrix multiplication *
 *************************/

/**
 * Naive implementation of a matrix multiplication
 */
int standardMatrixMul(Matrix a, Matrix b, Matrix *result);

/**
 * Cache optimized implemetation of a matrix multiplication
 */
int optimizedMatrixMul(Matrix a, Matrix b, Matrix *result, int termination);

/**
 * Parallel implementation of a matrix multiplication
 */
int parallelMatrixMul(Matrix a, Matrix b, Matrix *result);

#endif // MATRIX_H
