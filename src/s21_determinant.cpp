#include "s21_matrix_oop.h"

double S21Matrix::Determinant() {
    if (rows_ != cols_) {
        throw CustomException("invalid size");
    } else if (rows_ == 1) {
        return matrix_[0];
    } else {
        return Det();
    }
}

double S21Matrix::Det() {
    int n = rows_;
    if (n == 1)
        return matrix_[0];

    double determ = 0;
    int sign = 1;
    for (int i = 0; i < n; ++i) {
        S21Matrix cof = GetCofactor(0, i);
        determ += sign * operator()(0, i) * cof.Det();
        sign = -sign;
    }
    return determ;
}

S21Matrix S21Matrix::GetCofactor(int row, int col) {
    int n = rows_;
    S21Matrix res(n - 1, n - 1);
    for (int i = 0, c = 0, r = 0; i < n; ++i) {
        if (i == row)
            r = 1;
        c = 0;
        for (int j = 0; j < n; ++j) {
            if (j == col)
                c = 1;
            if (i != row && j != col)
                res(i - r, j - c) = operator()(i, j);
        }
    }
    return res;
}
