#include <gtest/gtest.h>

#include "../s21_matrix_oop.h"

TEST(test_determinant, normal) {
    int exp = 0;

    int rows = 3;
    int cols = 3;
    S21Matrix m(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            m(i, j) = i * cols + j;
        }
    }
    ASSERT_DOUBLE_EQ(m.Determinant(), 0);
}

TEST(test_determinant, normal2) {
    int exp = 0;

    int rows = 3;
    int cols = 3;
    S21Matrix m(rows, cols);
    m(0, 0) = 4;
    m(0, 1) = 5;
    m(0, 2) = 1;

    m(1, 0) = 23;
    m(1, 1) = 3;
    m(1, 2) = 1;

    m(2, 0) = 2;
    m(2, 1) = 3;
    m(2, 2) = 7;
    ASSERT_DOUBLE_EQ(m.Determinant(), -660);
}

TEST(test_determinant, one_by_one) {
    int exp = 5;

    int rows = 1;
    int cols = 1;
    S21Matrix m(rows, cols);

    m(0, 0) = 5;

    ASSERT_DOUBLE_EQ(m.Determinant(), 5);
}

TEST(test_determinant, invalid) {
    int exp = 5;

    int rows = 5;
    int cols = 3;
    S21Matrix m(rows, cols);

    ASSERT_ANY_THROW(m.Determinant());
}