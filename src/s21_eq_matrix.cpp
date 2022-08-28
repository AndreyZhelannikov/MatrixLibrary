#include "s21_matrix_oop.h"

bool S21Matrix::EqMatrix(const S21Matrix& other) {
    if (rows_ == other.rows_ && cols_ == other.cols_) {
        for (int i = 0; i < rows_; ++i) {
            for (int j = 0; j < cols_; ++j) {
                if (fabs(matrix_[i * cols_ + j] - other.matrix_[i * cols_ + j]) > 1e-6)
                    return false;
            }
        }
    } else {
        return false;
    }
    return true;
}
