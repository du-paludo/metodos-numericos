// Eduardo Stefanel Paludo - GRR20210581
// Fábio Naconeczny da Silva - GRR20211782

#include "helpers.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


// Imprime o sistema A|B
void printSystem(double** A, double* b, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%lf ", A[i][j]);
        }
        printf("%lf\n", b[i]);
    }
    printf("\n");
}

// Imprime o vetor solução com 12 casas decimais
void printSolution(double* x, int n) {
    for (int i = 0; i < n-1; i++) {
        printf("%.12lf ", x[i]);
    }
    printf("%.12lf\n", x[n-1]);
}

// Imprime o resíduo b - Ax
void printResidual(double** A, double* b, double* x, int n) {
    double residual;
    for (int i = 0; i < n; i++) {
        residual = 0.0;
        for (int j = 0; j < n; j++) {
            residual += A[i][j] * x[j];
        }
        residual -= b[i];
        if (i == n - 1) {
            printf("%.12lf\n", residual);
        } else {
            printf("%.12lf ", residual);
        }
    }
}

// Encontra o pivô utilizado na Eliminação de Gauss
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

// Troca duas linhas de lugar
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

// Copia a matriz A para B
void copyArray(double** A, double** B, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            B[i][j] = A[i][j];
        }
    }
}
