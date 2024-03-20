#include "methods.h"
#include "helpers.h"
#include <math.h>
#include <stdlib.h>

#define MAXIT 50
#define MAXERROR 0.0001

void gauss(double** A, double* b, double* x, int n) {
    for (int i = 0; i < n; i++) {
        int pivotIndex = findMax(A, i, n);

        if (pivotIndex != i) {
            swapRow(A, i, pivotIndex);
        }

        for (int k = i+1; k < n; k++) {
            double m = A[k][i] / A[i][i];
            A[k][i] = 0;
            for (int j = i+1; j < n; j++) {
                A[k][j] -= A[i][j] * m;
            }
            b[k] -= b[i] * m;
        }
    }

    for (int i = n-1; i >= 0; i--) {
        x[i] = b[i];
        for (int j = i+1; j < n; j++) {
            x[i] -= A[i][j] * x[j];
        }
        x[i] /= A[i][i];
    }
}

void gaussSeidel(double** A, double* b, double* x, int n) {
    for (int i = 0; i < n; i++) {
        x[i] = 0;
    }
    for (int k = 0; k < MAXIT; k++) {
        double maxNorm = 0;
        for (int i = 0; i < n; i++) {
            double oldX = x[i];
            x[i] = b[i];
            for (int j = 0; j < n; j++) {
                if (j == i) {
                    continue;
                }
                x[i] -= A[i][j] * x[j];
            }
            x[i] /= A[i][i];
            if (fabs(x[i] - oldX) > maxNorm) {
                maxNorm = x[i] - oldX;
            }
        }
        if (maxNorm < MAXERROR) {
            break;
        }
    }
}

void gaussTridiagonal(double** A, double* b, double* x, int n) {
    for (int i = 0; i < n-1; i++) {
        double m = A[i+1][i] / A[i][i];
        A[i+1][i] = 0;
        A[i+1][i+1] -= A[i][i+1] * m;
        b[i+1] -= b[i] * m;
    }

    x[n-1] = b[n-1] / A[n-1][n-1];
    for (int i = n-2; i >= 0; i--) {
        x[i] = (b[i] - A[i][i+1] * x[i+1]) / A[i][i];
    }
}

void gaussSeidelTridiagonal(double** A, double* b, double* x, int n) {
    double* oldX = (double*) malloc(sizeof(double) * n);
    for (int i = 0; i < n; i++) {
        x[i] = 0;
    }
    for (int k = 0; k < MAXIT; k++) {
        oldX[0] = x[0];
        x[0] = (b[0] - A[0][1] * x[1]) / A[0][0];
        double maxNorm = x[0] - oldX[0];
        for (int i = 1; i < n-1; i++) {
            oldX[i] = x[i];
            x[i] = (b[i] - A[i][i-1] * x[i-1] - A[i][i+1] * x[i+1]) / A[i][i];
            if (fabs(x[i] - oldX[i]) > maxNorm) {
                maxNorm = x[i] - oldX[i];
            }
        }
        oldX[n-1] = x[n-1];
        x[n-1] = (b[n-1] - A[n-1][n-2] * x[n-2]) / A[n-1][n-1];
        if (fabs(x[n-1] - oldX[n-1]) > maxNorm) {
            maxNorm = x[n-1] - oldX[n-1];
        }
        if (maxNorm < MAXERROR) {
            break;
        }
    }
    free(oldX);
}