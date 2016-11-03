#ifndef MATRIXMULTIPLICATION_H
#define MATRIXMULTIPLICATION_H

#include "Matrix.h"

Matrix standardMatrixMul(Matrix a, Matrix b);

Matrix optimizedMatrixMul(Matrix a, Matrix b, int termination);

Matrix parallelMatrixMul(Matrix a, Matrix b);

#endif // MATRIXMULTIPLICATION_H
