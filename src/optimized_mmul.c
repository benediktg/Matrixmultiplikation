#include <stdio.h>

#include "include/Matrix.h"

void recursiveMatrixMul(Matrix m1, int i1, int j1,
                        Matrix m2, int i2, int j2,
                        int size, int t, Matrix *result);

void normalMatrixMul(Matrix m1, int i1, int j1,
                     Matrix m2, int i2, int j2,
                     int size, Matrix *result);

int optimizedMatrixMul(Matrix a, Matrix b, Matrix *result, int termination)
{
    if (a.columnCount != b.rowCount) {
        printf("Error: wrong matrix dimensions.\n");
        return 1;
    } else if (!(isSquareMatrix(a))
            || !(isSquareMatrix(b))) {
        printf("Error: please provide square matrices.\n");
        return 2;
    }

    recursiveMatrixMul(a, 0, 0, b, 0, 0, a.rowCount, termination, result);

    return 0;
}

void recursiveMatrixMul(Matrix m1, int i1, int j1,
                        Matrix m2, int i2, int j2,
                        int size, int t, Matrix *result)
{
    if (size == 1) {
        addToElementValue(result, i1, j2,
                          getElementValue(m1, i1, j1)
                          * getElementValue(m2, i2, j2));
    } else if (size % 2 || size <= t) {
        // break condition: no further splitting reasonable
        normalMatrixMul(m1, i1, j1, m2, i2, j2, size, result);
    } else {
        /*  /G  H\   /K  L\   / GK+HM  GL+HN \
         *  |    | × |    | = |              |
         *  \I  J/   \M  N/   \ IK+JM  IL+JN /
         */

        int s = size / 2;

        // GK
        recursiveMatrixMul(m1, i1, j1, m2, i2, j2, s, t, result);
        // + HM
        recursiveMatrixMul(m1, i1, j1 + s, m2, i2 + s, j2, s, t, result);

        // GL
        recursiveMatrixMul(m1, i1, j1, m2, i2, j2 + s, s, t, result);
        // + HN
        recursiveMatrixMul(m1, i1, j1 + s, m2, i2 + s, j2 + s, s, t, result);

        // IK
        recursiveMatrixMul(m1, i1 + s, j1, m2, i2, j2, s, t, result);
        // + JM
        recursiveMatrixMul(m1, i1 + s, j1 + s, m2, i2 + s, j2, s, t, result);

        // IL
        recursiveMatrixMul(m1, i1 + s, j1, m2, i2, j2 + s, s, t, result);
        // + JN
        recursiveMatrixMul(m1, i1 + s, j1 + s, m2, i2 + s, j2 + s, s, t, result);
    }
}

void normalMatrixMul(Matrix m1, int i1, int j1,
                     Matrix m2, int i2, int j2,
                     int size, Matrix* result)
{
    //#pragma omp parallel for collapse(2)
    for (int i = i1; i < i1 + size; ++i) {
        for (int j = j2; j < j2 + size; ++j) {
            for (int k = j1, l = i2; k < j1 + size && l < i2 + size; ++k, ++l) {
                addToElementValue(result, i, j,
                        getElementValue(m1, i, k) * getElementValue(m2, l, j));
            }
        }
    }
}
