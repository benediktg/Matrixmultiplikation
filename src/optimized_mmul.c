#include "Matrix.h"
#include "matrixmultiplication.h"

Matrix optimizedMatrixMul(Matrix a, Matrix b, int termination)
{
    if ((a.columnCount != b.rowCount)
            || !(isSymmetricMatrix(a))
            || !(isSymmetricMatrix(b))) {
        return newMatrix(0, 0);
    }

    Matrix result = newMatrix(a.rowCount, b.columnCount);
    // do the optimized calculation
    return result;
}
