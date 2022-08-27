#include "s21_matrix_oop.h"

S21Matrix S21Matrix::CalcComplements() {
    int n = rows_;
    S21Matrix res(n, n);
    if (rows_ != cols_ || rows_ == 1) {
        throw CustomException("Incorrect matrix");
    } else {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                S21Matrix cof = GetCofactor(i, j);
                double det = cof.Determinant();
                res(i, j) = det * std::pow(-1, i + j);
            }
        }
    }
    return res;
}

// int s21_calc_complements(matrix_t *A, matrix_t *result) {
//     if (is_incorrect(A))
//         return INCORRECT_MATRIX;
//     if (A->rows != A->columns || A->rows == 1)
//         return CALC_ERROR;

//     int code = OK;
//     int n = A->rows;
//     matrix_t tmp;
//     int codec1, codec2;
//     codec1 = s21_create_matrix(A->rows - 1, A->columns - 1, &tmp);
//     if (!codec1)
//         codec2 = s21_create_matrix(n, n, result);
//     if (!codec1 && !codec2) {
//         for (int i = 0; i < n; ++i) {
//             for (int j = 0; j < n; ++j) {
//                 double det = 0;
//                 get_cofactor(A, &tmp, i, j, n);  // rows : columns
//                 s21_determinant(&tmp, &det);
//                 result->matrix[i][j] = det * pow(-1, i + j);
//             }
//         }
//         s21_remove_matrix(&tmp);
//     }
//     return code;
// }
