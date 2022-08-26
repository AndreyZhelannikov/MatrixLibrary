#include "s21_matrix_oop.h"

S21Matrix::S21Matrix() {
    rows_ = DEFAULT_MATRIX_ROWS;
    cols_ = DEFAULT_MATRIX_COLS;
    if (rows_ > 0 && cols_ > 0) {
        matrix_ = new double[rows_ * cols_]();
    } else {
        throw CustomException("incorrect matrix");
    }
}

S21Matrix::S21Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
    if (rows_ > 0 && cols_ > 0) {
        matrix_ = new double[rows_ * cols_]();
    } else {
        throw CustomException("incorrect matrix");
    }
}

S21Matrix::S21Matrix(const S21Matrix& other) : rows_(other.rows_), cols_(other.cols_) {
    matrix_ = new double[rows_ * cols_]();
}