#include "s21_matrix_oop.h"

double& S21Matrix::operator()(int row, int col) {
    if (row >= rows_ || col >= cols_) {
        throw std::out_of_range("Incorrect input, index is out of range");
    }
    return matrix_[row * cols_ + col];
}

double S21Matrix::operator()(int row, int col) const {
    if (row >= rows_ || col >= cols_) {
        throw std::out_of_range("Incorrect input, index is out of range");
    }
    return matrix_[row * cols_ + col];
}

S21Matrix& S21Matrix::operator=(const S21Matrix& other) {
    if (this == &other)
        return *this;

    SetSize(other.rows_, other.cols_);
    std::memcpy(matrix_, other.matrix_, other.rows_ * other.cols_ * sizeof(double));
    return *this;
}

S21Matrix S21Matrix::operator+(const S21Matrix& other) {
    S21Matrix res = *this;
    res.SumMatrix(other);
    return res;
}
S21Matrix& S21Matrix::operator+=(const S21Matrix& other) {
    this->SumMatrix(other);
    return *this;
}

S21Matrix S21Matrix::operator-(const S21Matrix& other) {
    S21Matrix res = *this;
    res.SubMatrix(other);
    return res;
}
S21Matrix& S21Matrix::operator-=(const S21Matrix& other) {
    this->SubMatrix(other);
    return *this;
}

S21Matrix S21Matrix::operator*(const S21Matrix& other) {
    S21Matrix res = *this;
    res.MulMatrix(other);
    return res;
}

S21Matrix operator*(double n, const S21Matrix& m) {
    S21Matrix res = m;
    res.MulNumber(n);
    return res;
}
S21Matrix operator*(const S21Matrix& m, double n) {
    S21Matrix res = m;
    res.MulNumber(n);
    return res;
}

S21Matrix& S21Matrix::operator*=(const S21Matrix& other) {
    this->MulMatrix(other);
    return *this;
}

S21Matrix& S21Matrix::operator*=(const double number) {
    this->MulNumber(number);
    return *this;
}

bool S21Matrix::operator==(const S21Matrix& other) {
    return (this->EqMatrix(other));
}
