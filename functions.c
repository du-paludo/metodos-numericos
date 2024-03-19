#include "functions.h";
#include <stdio.h>

int findMax(double** A, int i, int n) {
    int pivotIndex = i;
    int pivotValue = A[pivotIndex][i];

    for (int k = i + 1; k < n; k++) {
        if (abs(A[k][i]) > pivotValue) {
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

void eliminacaoGauss(double** A, double* b, int n) {
    for (int i = 0; i < n; i++) {
        int pivotIndex = findMax(A, i, n);

        if (pivotIndex != i) {
            swapRow(A, i, pivotIndex);
        }

        for (int k = i+1; k < n; k++) {
            double m = A[k][i] / A[i][i];
            A[k][i] = 0;
            for (int j = k+1; j < n; j++) {
                A[k][j] -= m * A[i][j];
            }
            b[k] -= m * b[i];
        }
    }
}

void backSubstitution(double** A, double* b, double* x, int n) {
    for (int i = n-1; i >= 0; i--) {
        x[i] = b[i];
        for (int j = i+1; j < n; j++) {
            b[i] -= A[i][j] * x[j];
        }
        x[i] /= A[i][i];
    }
}