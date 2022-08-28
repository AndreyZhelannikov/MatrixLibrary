#ifndef S21_MATRIX
#define S21_MATRIX

#define DEFAULT_MATRIX_ROWS 3
#define DEFAULT_MATRIX_COLS 3

#include <cmath>
#include <cstring>
#include <iostream>

#include "matrix_exceptions.h"

class S21Matrix {
   private:
    int rows_, cols_;
    double* matrix_;

    double Det();
    S21Matrix GetCofactor(int row, int col);

   public:
    S21Matrix();
    S21Matrix(int rows, int cols);
    S21Matrix(const S21Matrix& other);
    S21Matrix(S21Matrix&& other);

    ~S21Matrix();

    int GetRows();
    int GetCols();
    void SetRows(int rows);
    void SetCols(int cols);
    void SetSize(int rows, int cols);
    void PrintMatrix();

    bool EqMatrix(const S21Matrix& other);

    void SumMatrix(const S21Matrix& other);
    void SubMatrix(const S21Matrix& other);
    void MulNumber(const double num);
    void MulMatrix(const S21Matrix& other);
    S21Matrix Transpose();
    S21Matrix CalcComplements();
    S21Matrix InverseMatrix();
    double Determinant();

    S21Matrix operator+(const S21Matrix& other);
    S21Matrix& operator+=(const S21Matrix& other);
    S21Matrix operator-(const S21Matrix& other);
    S21Matrix& operator-=(const S21Matrix& other);
    S21Matrix operator*(const S21Matrix& other);
    S21Matrix& operator*=(const S21Matrix& other);
    S21Matrix& operator*=(const double number);
    friend S21Matrix operator*(double n, const S21Matrix& m);
    friend S21Matrix operator*(const S21Matrix& m, double n);
    bool operator==(const S21Matrix& other);

    double& operator()(int row, int col);
    double operator()(int row, int col) const;
    S21Matrix& operator=(const S21Matrix& other);
};

#endif  // S21_MATRIX