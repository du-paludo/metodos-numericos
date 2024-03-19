#ifndef FUNCTIONS_H
#define FUNCTIONS_H

int findMax(double** A, int i, int n);

void swapRow(double** A, int i, int pivotIndex);

void gaussElimination(double** A, double* b, int n);

void backSubstitution(double** A, double* b, double* x, int n);

#endif