#include <stdio.h>
#include <time.h>

#include "include/Matrix.h"

#include "matrix_macros.txt"
float data1[MATRIX_SIZE * MATRIX_SIZE] = {MATRIX_1};
float data2[MATRIX_SIZE * MATRIX_SIZE] = {MATRIX_2};

int main(void)
{
    Matrix m1 = {MATRIX_SIZE, MATRIX_SIZE, data1};
    Matrix m2 = {MATRIX_SIZE, MATRIX_SIZE, data2};

    clock_t start, end;
    float cpu_time_used;

    start = clock();
    Matrix result = allocMatrix(m1, m2);
    end = clock();
    cpu_time_used = ((float) (end - start)) / CLOCKS_PER_SEC;
    printf("time for allocation:  %f seconds\n", cpu_time_used);

    start = clock();
    standardMatrixMul(m1, m2, &result);
    end = clock();
    cpu_time_used = ((float) (end - start)) / CLOCKS_PER_SEC;
    printf("time for calculation: %f seconds\n", cpu_time_used);

    start = clock();
    freeMatrix(&result);
    end = clock();
    cpu_time_used = ((float) (end - start)) / CLOCKS_PER_SEC;
    printf("time for freeing:     %f seconds\n", cpu_time_used);

    return 0;
}
