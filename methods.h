#ifndef METHODS_H
#define METHODS_H

void gaussElimination(double** A, double* b, double* x, int n);

int gaussSeidel(double** A, double* b, double* x, int n);

void gaussEliminationTridiagonal(double** A, double* b, double* x, int n);

int gaussSeidelTridiagonal(double** A, double* b, double* x, int n);

#endif