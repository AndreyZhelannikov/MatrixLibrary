#include "s21_matrix_oop.h"

void S21Matrix::MulNumber(const double num) {
    for (int i = 0; i < rows_ * cols_; i++) {
        matrix_[i] *= num;
    }
}
