#include <gtest/gtest.h>

#include "../s21_matrix_oop.h"

TEST(test_mult_matrix, normal) {
    int rows = 3;
    int cols = 2;

    S21Matrix m1(rows, cols);
    S21Matrix m2(cols, rows);

    S21Matrix mul(rows, rows);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            m1(i, j) = i * cols + j;
        }
    }
    for (int i = 0; i < cols; ++i) {
        for (int j = 0; j < rows; ++j) {
            m2(i, j) = i * rows + j;
        }
    }

    mul(0, 0) = 3;
    mul(0, 1) = 4;
    mul(0, 2) = 5;

    mul(1, 0) = 9;
    mul(1, 1) = 14;
    mul(1, 2) = 19;

    mul(2, 0) = 15;
    mul(2, 1) = 24;
    mul(2, 2) = 33;

    m1.MulMatrix(m2);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < rows; ++j) {
            ASSERT_DOUBLE_EQ(m1(i, j), mul(i, j));
        }
    }
}

TEST(test_mult_matrix, incorrect) {
    S21Matrix m1(2, 2);
    S21Matrix m2(3, 3);
    ASSERT_ANY_THROW(m1.MulMatrix(m2));
}
