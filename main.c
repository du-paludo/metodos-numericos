#include "helpers.h"
#include "methods.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

#include <likwid.h>

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

    double** Acopy = (double**) malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++) {
        Acopy[i] = (double*) malloc(n * sizeof(double));
    }
    copyArray(A, Acopy, n);

    double time;
    int it;

    LIKWID_MARKER_INIT;

    // Gauss Elimination
    LIKWID_MARKER_START ("EG_Clássico");
    time = timestamp();
    gaussElimination(Acopy, b, x, n);
    time = timestamp() - time;
    LIKWID_MARKER_STOP ("EG_Clássico");
    
    printf("EG clássico:\n");
    printf("%lf ms\n", time);
    printSolution(x, n);
    printResidue(A, b, x, n);
    printf("\n");

    // Gauss-Seidel
    LIKWID_MARKER_START ("GS_Clássico");
    time = timestamp();
    it = gaussSeidel(A, b, x, n);
    time = timestamp() - time;
    LIKWID_MARKER_STOP ("GS_Clássico");

    printf("GS clássico [ %d iterações ]:\n", it);
    printf("%lf ms\n", time);
    printSolution(x, n);
    printResidue(A, b, x, n);
    printf("\n");

    copyArray(A, Acopy, n);

    // 3-diagonal Gauss Elimination
    LIKWID_MARKER_START ("EG_3-Diagonal");
    time = timestamp();
    gaussEliminationTridiagonal(Acopy, b, x, n);
    time = timestamp() - time;
    LIKWID_MARKER_STOP ("EG_3-Diagonal");

    printf("EG 3-diagonal:\n");
    printf("%lf ms\n", time);
    printSolution(x, n);
    printResidue(A, b, x, n);
    printf("\n");

    // 3-diagonal Gauss-Seidel
    LIKWID_MARKER_START ("GS_3-Diagonal");
    time = timestamp();
    it = gaussSeidelTridiagonal(A, b, x, n);
    time = timestamp() - time;
    LIKWID_MARKER_STOP ("GS_3-Diagonal");

    printf("GS 3-diagonal [ %d iterações ]:\n", it);
    printf("%lf ms\n", time);
    printSolution(x, n);
    printResidue(A, b, x, n);
    
    LIKWID_MARKER_CLOSE;

    // Libera a memória alocada
    for (int i = 0; i < n; i++) {
        free(A[i]);
        free(Acopy[i]);
    }
    free(A);
    free(Acopy);
    free(b);
    free(x);

    return 0;
}