#include "helpers.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void printSystem(double** A, double* b, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%lf ", A[i][j]);
        }
        printf("%lf\n", b[i]);
    }
    printf("\n");
}

void printSolution(double* x, int n) {
    for (int i = 0; i < n-1; i++) {
        printf("%lf ", x[i]);
    }
    printf("%lf\n", x[n-1]);
}

int findMax(double** A, int i, int n) {
    int pivotIndex = i;
    int pivotValue = A[pivotIndex][i];

    for (int k = i + 1; k < n; k++) {
        if (fabs(A[k][i]) > pivotValue) {
            pivotValue = A[k][i];
            pivotIndex = k;
        }
    }
    
    return pivotIndex;
}

void swapRow(double** A, int i, int pivotIndex) {
    double* temp = A[i];
    A[i] = A[pivotIndex];
    A[pivotIndex] = temp;
}