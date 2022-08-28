#include <gtest/gtest.h>

#include "../s21_matrix_oop.h"

TEST(test_inverse_matrix, normal) {
    int n = 3;
    S21Matrix m(n, n);
    S21Matrix exp(n, n);

    m(0, 0) = 2;
    m(0, 1) = 5;
    m(0, 2) = 7;

    m(1, 0) = 6;
    m(1, 1) = 3;
    m(1, 2) = 4;

    m(2, 0) = 5;
    m(2, 1) = -2;
    m(2, 2) = -3;

    exp(0, 0) = 1;
    exp(0, 1) = -1;
    exp(0, 2) = 1;

    exp(1, 0) = -38;
    exp(1, 1) = 41;
    exp(1, 2) = -34;

    exp(2, 0) = 27;
    exp(2, 1) = -29;
    exp(2, 2) = 24;

    S21Matrix res = m.InverseMatrix();

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            ASSERT_DOUBLE_EQ(res(i, j), exp(i, j));
        }
    }
}

TEST(test_inverse_matrix, det_zero) {
    int n = 3;
    S21Matrix m(n, n);
    S21Matrix exp(n, n);

    m(0, 0) = 0;
    m(0, 1) = 1;
    m(0, 2) = 2;

    m(1, 0) = 3;
    m(1, 1) = 4;
    m(1, 2) = 5;

    m(2, 0) = 6;
    m(2, 1) = 7;
    m(2, 2) = 8;

    ASSERT_ANY_THROW(m.InverseMatrix());
}

TEST(test_inverse_matrix, rnec) {
    int n = 3;
    S21Matrix m(n + 1, n);

    ASSERT_ANY_THROW(m.InverseMatrix());
}

TEST(test_inverse_matrix, two_by_two) {
    S21Matrix m(2, 2);
    S21Matrix exp(2, 2);

    m(0, 0) = 6;
    m(0, 1) = 4;

    m(1, 0) = 4;
    m(1, 1) = 5;

    exp(0, 0) = 5.0 / 14.0;
    exp(0, 1) = -2.0 / 7.0;

    exp(1, 0) = -2.0 / 7.0;
    exp(1, 1) = 3.0 / 7.0;

    S21Matrix res = m.InverseMatrix();

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            ASSERT_DOUBLE_EQ(res(i, j), exp(i, j));
        }
    }
}

TEST(test_inverse_matrix, one_by_one) {
    S21Matrix m(1, 1);
    m(0, 0) = 5;
    S21Matrix res = m.InverseMatrix();
    res.PrintMatrix();
    ASSERT_DOUBLE_EQ(res(0, 0), 1.0 / 5.0);
}
