#include "s21_matrix_oop.h"

S21Matrix::S21Matrix() {
    rows_ = DEFAULT_MATRIX_ROWS;
    cols_ = DEFAULT_MATRIX_COLS;
}

S21Matrix::S21Matrix(int rows, int cols) {
    rows_ = rows;
    cols_ = cols;
    if (rows_ > 0 && cols_ > 0) {
        matrix_ = (double **)(calloc(1, rows_ * cols_ * sizeof(double) + rows_ * sizeof(double *)));
        if (matrix_) {
            double *ptr = (double *)(matrix_ + rows_);
            for (int i = 0; i < rows_; ++i) {
                matrix_[i] = ptr + cols * i;
            }
        } else {
            // code = CALC_ERROR;
            ;
        }
    } else {
        ;
        // code = INCORRECT_MATRIX;
    }
}