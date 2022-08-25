
#define DEFAULT_MATRIX_ROWS 3
#define DEFAULT_MATRIX_COLS 3

#include <iostream>
#include <vector>

class S21Matrix {
   private:
    int rows_, cols_;
    double** matrix_;

   public:
    S21Matrix();
    S21Matrix(int rows, int cols);
    // S21Matrix(const S21Matrix& other);
    // S21Matrix(S21Matrix&& other);

    // ~S21Matrix();

    int getRows();
    int getCols();
    void setRows(int rows);
    void setCols(int cols);

    bool EqMatrix(const S21Matrix& other);

    // void SumMatrix(const S21Matrix& other);
    // void SubMatrix(const S21Matrix& other);
    // void MulNumber(const double num);
    // void MulMatrix(const S21Matrix& other);
    // S21Matrix Transpose();
    // S21Matrix CalcComplements();
    // double Determinant();
    // S21Matrix InverseMatrix();
};
