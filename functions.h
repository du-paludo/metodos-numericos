#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void printSystem(double** A, double* b, int n);

void printSolution(double* x, int n);

int findMax(double** A, int i, int n);

void swapRow(double** A, int i, int pivotIndex);

void gaussElimination(double** A, double* b, int n);

void backSubstitution(double** A, double* b, double* x, int n);

void gaussSeidel(double** A, double* b, double* x, int n);

void gaussTridiagonal(double** A, double* b, double* x, int n);

void gaussSeidelTridiagonal(double** A, double* b, double* x, int n);

#endif