# Numerical Methods

This project implements a few numerical methods used for solving systems of linear equations. Input consists in a number $n$ representing the order of coefficient matrix, which must be square. Then, a matrix $n \times n+1$ follow, where the last column represents the vector of constant terms. Then, the Gaussian Elimination and Gauss-Seidel methods, as well as optimized versions of these algorithms for 3-diagonal coefficient matrices, are used to solve the system. The LIKWID library is used to track performance of each of these methods.
