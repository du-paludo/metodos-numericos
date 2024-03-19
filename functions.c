#include "functions.h";
#include <stdio.h>

void readInput(double** A, double* B) {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &A[i][j]);
        }
        scanf("%lf", &B[i]);
    }
}