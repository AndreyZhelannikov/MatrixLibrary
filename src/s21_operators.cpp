#include "s21_matrix_oop.h"

double& S21Matrix::operator()(int row, int col) {
    if (row >= rows_ || col >= cols_) {
        throw std::out_of_range("Incorrect input, index is out of range");
    }
    return matrix_[row * cols_ + col];
}

double S21Matrix::operator()(int row, int col) const {
    if (row >= rows_ || col >= cols_) {
        throw std::out_of_range("Incorrect input, index is out of range");
    }
    return matrix_[row * cols_ + col];
}