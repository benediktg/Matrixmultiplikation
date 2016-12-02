#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "include/Matrix.h"

#include "matrix_macros.txt"
float data1[MATRIX_SIZE * MATRIX_SIZE] = {MATRIX_1};
float data2[MATRIX_SIZE * MATRIX_SIZE] = {MATRIX_2};

int main(int argc, char **argv)
{
    Matrix m1 = {MATRIX_SIZE, MATRIX_SIZE, data1};
    Matrix m2 = {MATRIX_SIZE, MATRIX_SIZE, data2};

    clock_t start, end;
    float cpu_time_used;
    Matrix result1 = allocMatrix(m1, m2);
    Matrix result2 = allocMatrix(m1, m2);

    start = clock();
    standardMatrixMul(m1, m2, &result1);
    end = clock();
    cpu_time_used = ((float) (end - start)) / CLOCKS_PER_SEC;
    printf("time for standard:  %f seconds\n", cpu_time_used);

    int termination;
    if (argc == 2) {
        char *endptr;
        termination = strtoimax(argv[1], &endptr, 10);
    } else {
        termination = 1;
    }
    start = clock();
    optimizedMatrixMul(m1, m2, &result2, termination);
    end = clock();
    cpu_time_used = ((float) (end - start)) / CLOCKS_PER_SEC;
    printf("time for optimized: %f seconds\n", cpu_time_used);

    if (areEqualMatrices(result1, result2)) {
        printf("correct result\n");
    } else {
        printf("wrong result\n");
    }

    freeMatrix(&result1);
    freeMatrix(&result2);

    return 0;
}
