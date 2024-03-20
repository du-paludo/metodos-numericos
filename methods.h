#ifndef METHODS_H
#define METHODS_H

void gauss(double** A, double* b, double* x, int n);

void gaussSeidel(double** A, double* b, double* x, int n);

void gaussTridiagonal(double** A, double* b, double* x, int n);

void gaussSeidelTridiagonal(double** A, double* b, double* x, int n);

#endif