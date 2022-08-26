#ifndef S21_MATRIX
#define S21_MATRIX

#define DEFAULT_MATRIX_ROWS 3
#define DEFAULT_MATRIX_COLS 3

#include <cmath>
#include <iostream>

#include "matrix_exceptions.h"

class S21Matrix {
   private:
    int rows_, cols_;
    double* matrix_;

   public:
    S21Matrix();
    S21Matrix(int rows, int cols);
    S21Matrix(const S21Matrix& other);
    // S21Matrix(S21Matrix&& other);

    // ~S21Matrix();

    int GetRows();
    int GetCols();
    void SetRows(int rows);
    void SetCols(int cols);
    void PrintMatrix();

    bool EqMatrix(const S21Matrix& other);

    void SumMatrix(const S21Matrix& other);
    void SubMatrix(const S21Matrix& other);
    void MulNumber(const double num);
    void MulMatrix(const S21Matrix& other);
    S21Matrix Transpose();
    S21Matrix CalcComplements();
    double Determinant();
    S21Matrix InverseMatrix();
};

#endif  // S21_MATRIX