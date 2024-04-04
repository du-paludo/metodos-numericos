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
        printf("%.12lf ", x[i]);
    }
    printf("%.12lf\n", x[n-1]);
}

void printResidue(double** A, double* b, double* x, int n) {
    double residue;
    for (int i = 0; i < n; i++) {
        residue = 0;
        for (int j = 0; j < n; j++) {
            residue += A[i][j] * x[j];
        }
        residue -= b[i];
        if (i == n - 1) {
            printf("%.12lf\n", residue);
        } else {
            printf("%.12lf ", residue);
        }
    }
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

void swapRow(double **A, double *B, int row1, int row2, int n) {
    // Troca os elementos da linha row1 com a linha row2 na matriz A
    double temp;
    for (int j = 0; j < n; ++j) {
        temp = A[row1][j];
        A[row1][j] = A[row2][j];
        A[row2][j] = temp;
    }
    // Troca os elementos no vetor B
    temp = B[row1];
    B[row1] = B[row2];
    B[row2] = temp;
}

void copyArray(double** A, double** B, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            B[i][j] = A[i][j];
        }
    }
}
