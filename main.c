#include "functions.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    // Aloca memória
    double** A = (double**) malloc(n * sizeof(double*));
    double* b = (double*) malloc(n * sizeof(double));

    for (int i = 0; i < n; i++) {
        A[i] = (double*) malloc(n * sizeof(double));
        for (int j = 0; j < n; j++) {
            scanf("%lf", &A[i][j]);
        }
        scanf("%lf", &b[i]);
    }

    double* x = (double*) malloc(n * sizeof(double));

    // gaussElimination(A, b, n);
    // backSubstitution(A, b, x, n);

    // gaussSeidel(A, b, x, n);
    gaussTridiagonal(A, b, x, n);

    printSolution(x, n);

    // Libera a memória alocada
    for (int i = 0; i < n; i++) {
        free(A[i]);
    }
    free(A);
    free(b);
    free(x);

    return 0;
}