#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "include/Matrix.h"

#include "matrix_macros.txt"
float data1[MATRIX_SIZE * MATRIX_SIZE] = {MATRIX_1};
float data2[MATRIX_SIZE * MATRIX_SIZE] = {MATRIX_2};

int main(int argc, char **argv)
{
    int termination;
    if (argc == 2) {
        char *endptr;
        termination = strtol(argv[1], &endptr, 10);
    } else {
        termination = 1;
    }

    Matrix m1 = {MATRIX_SIZE, MATRIX_SIZE, data1};
    Matrix m2 = {MATRIX_SIZE, MATRIX_SIZE, data2};

    float st, en;
    clock_t start, end;
    float cpu_time_used, real_time_passed;
    Matrix result1 = allocMatrix(m1, m2);
    Matrix result2 = allocMatrix(m1, m2);
    Matrix result3 = allocMatrix(m1, m2);

    start = clock();
    st = omp_get_wtime();
    standardMatrixMul(m1, m2, &result1);
    end = clock();
    en = omp_get_wtime();
    cpu_time_used = ((float) (end - start)) / CLOCKS_PER_SEC;
    real_time_passed = (en - st);
    printf("CPU  time for standard:   %f seconds\n"
           "real time for standard:   %f seconds\n"
           "\n",
           cpu_time_used, real_time_passed);

    start = clock();
    st = omp_get_wtime();
    optimizedMatrixMul(m1, m2, &result2, termination);
    end = clock();
    en = omp_get_wtime();
    cpu_time_used = ((float) (end - start)) / CLOCKS_PER_SEC;
    real_time_passed = (en - st);
    printf("CPU  time for optimized:  %f seconds (termination: %d)\n"
           "real time for optimized:  %f seconds (termination: %d)\n"
           "\n",
           cpu_time_used, termination, real_time_passed, termination);

    start = clock();
    st = omp_get_wtime();
    parallelMatrixMul(m1, m2, &result3);
    end = clock();
    en = omp_get_wtime();
    cpu_time_used = ((float) (end - start)) / CLOCKS_PER_SEC;
    real_time_passed = (en - st);
    printf("CPU  time for parallel:   %f seconds\n"
           "real time for parallel:   %f seconds\n"
           "\n",
           cpu_time_used, real_time_passed);

    start = clock();
    st = omp_get_wtime();
    bool equals = areEqualMatrices(result1, result2)
                  && areEqualMatrices(result2, result3);
    end = clock();
    en = omp_get_wtime();
    cpu_time_used = ((float) (end - start)) / CLOCKS_PER_SEC;
    real_time_passed = (en - st);
    printf("CPU  time for comparison: %f seconds\n"
           "real time for comparison: %f seconds\n"
           "\n",
           cpu_time_used, real_time_passed);

    if (equals) {
        printf("correct result\n");
    } else {
        printf("wrong result\n");
    }

    freeMatrix(&result1);
    freeMatrix(&result2);
    freeMatrix(&result3);

    return 0;
}
