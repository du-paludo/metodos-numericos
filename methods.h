// Eduardo Stefanel Paludo - GRR20210581
// Fábio Naconeczny da Silva - GRR20211782

#ifndef METHODS_H
#define METHODS_H

void gaussElimination(double** A, double* b, double* x, int n);

int gaussSeidel(double** A, double* b, double* x, int n);

void gaussEliminationTridiagonal(double** A, double* b, double* x, int n);

int gaussSeidelTridiagonal(double** A, double* b, double* x, int n);

#endif
