#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    // Aloca memória
    double** A = (double**) malloc(n * sizeof(double*));
    double* B = (double*) malloc(n * sizeof(double));

    for (int i = 0; i < n; i++) {
        A[i] = (double*) malloc(n * sizeof(double));
        for (int j = 0; j < n; j++) {
            scanf("%lf", &A[i][j]);
        }
        scanf("%lf", &B[i]);
    }

    // Imprime o sistema
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         printf("%lf ", A[i][j]);
    //     }
    //     printf("%lf\n", B[i]);
    // }

    // Libera a memória alocada
    for (int i = 0; i < n; i++) {
        free(A[i]);
    }
    free(A);
    free(B);

    return 0;
}