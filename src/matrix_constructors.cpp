#include "s21_matrix_oop.h"

S21Matrix::S21Matrix() {
    rows_ = DEFAULT_MATRIX_ROWS;
    cols_ = DEFAULT_MATRIX_COLS;
    matrix_ = new double[rows_ * cols_]();
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
    std::memcpy(matrix_, other.matrix_, rows_ * cols_ * sizeof(double));
}

S21Matrix::S21Matrix(S21Matrix&& other) {
    if (rows_ * cols_ == other.rows_ * other.cols_) {
        std::memcpy(matrix_, other.matrix_, other.cols_ * other.rows_ * sizeof(double));
    } else {
        delete[] matrix_;
        matrix_ = new double[other.rows_ * other.cols_]();
        std::memcpy(matrix_, other.matrix_, other.cols_ * other.rows_ * sizeof(double));
    }
    rows_ = other.rows_;
    cols_ = other.cols_;
    delete other.matrix_;
    other.rows_ = 0;
    other.cols_ = 0;
}

S21Matrix::~S21Matrix() {
    if (matrix_) {
        delete[] matrix_;
    }
}
