#include "include/Matrix.h"
#include "standard_mmul.h"
#include "optimized_mmul.h"
#include "parallel_mmul.h"

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    double d1[] = {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9,
    };
    Matrix m1 = newMatrix(3, 3);
    m1.data = d1;
    double d2[] = {
        11, 12, 13,
        14, 15, 16,
        17, 18, 19,
    };
    Matrix m2 = newMatrix(3, 3);
    m2.data = d2;
    prettyPrint(m1);
    prettyPrint(m2);

    Matrix result = standardMatrixMul(m1, m2);
    prettyPrint(result);
    return 0;
}
