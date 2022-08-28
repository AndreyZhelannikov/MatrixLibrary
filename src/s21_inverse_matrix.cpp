#include "s21_matrix_oop.h"

S21Matrix S21Matrix::InverseMatrix() {
    if (rows_ != cols_)
        throw CustomException("Incorrect matrix");

    double det = Determinant();
    int n = rows_;
    S21Matrix res(n, n);
    if (std::fabs(det) > 1e-6) {
        if (n == 1) {
            res(0, 0) = 1.0 / operator()(0, 0);
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
