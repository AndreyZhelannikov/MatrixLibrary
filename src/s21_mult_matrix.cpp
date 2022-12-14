#include "s21_matrix_oop.h"

void S21Matrix::MulMatrix(const S21Matrix& other) {
    if (rows_ == other.cols_) {
        double* result = new double[rows_ * other.cols_]();
        for (int i = 0; i < rows_; ++i) {
            for (int j = 0; j < other.cols_; ++j) {
                for (int k = 0; k < other.rows_; ++k) {
                    result[i * other.cols_ + j] +=
                        matrix_[i * cols_ + k] * other.matrix_[k * other.cols_ + j];
                }
            }
        }
        if (matrix_)
            delete[] matrix_;
        matrix_ = result;

        cols_ = other.cols_;
    } else {
        throw CustomException("Invalid matrix size");
    }
}
