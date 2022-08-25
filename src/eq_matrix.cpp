#include "s21_matrix_oop.h"

bool S21Matrix::EqMatrix(const S21Matrix& other) {
    // int res = SUCCESS;

    //     if (is_eq_size(A, B)) {
    //         for (int i = 0; i < A->rows; i++) {
    //             for (int j = 0; j < A->columns; j++) {
    //                 if (fabs(A->matrix[i][j] - B->matrix[i][j]) > 1e-6) res = FAILURE;
    //             }
    //         }
    //     } else {
    //         res = FAILURE;
    //     }
    //     return res;
    // }
    if (rows_ == other.rows_ && cols_ == other.cols_)
        return true;
    return false;
}
