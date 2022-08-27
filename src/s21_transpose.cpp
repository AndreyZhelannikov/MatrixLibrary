#include "s21_matrix_oop.h"

S21Matrix S21Matrix::Transpose() {
    S21Matrix result(cols_, rows_);
    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < cols_; ++j) {
            result(j, i) = operator()(i, j);
        }
    }
    return result;
}
