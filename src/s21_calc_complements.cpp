#include "s21_matrix_oop.h"

S21Matrix S21Matrix::CalcComplements() {
    if (rows_ != cols_ || rows_ == 1)
        throw CustomException("Incorrect matrix");

    int n = rows_;
    S21Matrix res(n, n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            S21Matrix cof = GetCofactor(i, j);
            double det = cof.Determinant();
            res(i, j) = det * std::pow(-1, i + j);
        }
    }
    return res;
}
