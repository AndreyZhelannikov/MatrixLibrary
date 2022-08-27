#include "s21_matrix_oop.h"

void S21Matrix::SumMatrix(const S21Matrix& other) {
    if (rows_ * cols_ == other.rows_ * other.cols_) {
        for (int i = 0; i < rows_ * cols_; ++i) {
            matrix_[i] += other.matrix_[i];
        }
    } else {
        throw CustomException("the sum operation is valid only for matrices of the same size");
    }
}