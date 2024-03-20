#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void printSystem(double** A, double* b, int n);

void printSolution(double* x, int n);

void printResidue(double** A, double* b, double* x, int n);

int findMax(double** A, int i, int n);

void swapRow(double** A, int i, int pivotIndex);

void copyArray(double** A, double** B, int n);

#endif