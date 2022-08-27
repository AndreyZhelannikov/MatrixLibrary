#include "s21_matrix_oop.h"

S21Matrix S21Matrix::InverseMatrix() {
    if (rows_ != cols_)
        throw CustomException("Incorrect matrix");

    double det = Determinant();
    int n = rows_;
    S21Matrix res(n, n);
    if (std::fabs(det) > 1e-6) {
        if (n == 1) {
            S21Matrix res(n, n);
            res(0, 0) = 1.0 / operator()(0, 0);

            // return res;
        } else {
            res = CalcComplements().Transpose();
            res.MulNumber(1.0 / det);
            res.PrintMatrix();
        }
    } else {
        throw CustomException("Incorrect matrix");
    }
    return res;
}

// int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
//     double det = 0;

//     s21_determinant(A, &det);
//     int n = A->rows;
//     if (fabs(det) > 1e-6) {
//         if (n == 1) {
//             int codec = s21_create_matrix(n, n, result);
//             if (!codec)
//                 result->matrix[0][0] = 1.0 / A->matrix[0][0];
//         } else {
//             s21_calc_complements(A, result);
//             s21_transpose(result, &tmp);

//             s21_remove_matrix(result);

//             s21_mult_number(&tmp, 1.0 / det, result);

//             s21_remove_matrix(&tmp);
//         }
//     } else {
//         code = CALC_ERROR;
//     }
//     return code;
// }
