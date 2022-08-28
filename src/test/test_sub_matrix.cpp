#include <gtest/gtest.h>

#include "../s21_matrix_oop.h"

TEST(test_sub_matrix, normal) {
    int rows = 3;
    int cols = 3;
    S21Matrix m1(rows, cols);
    S21Matrix m2(rows, cols);
    S21Matrix exp(rows, cols);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            m1(i, j) = i * cols + j;
            m2(j, i) = i * cols + j;
        }
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            exp(i, j) = m1(i, j) - m2(i, j);
        }
    }
    m1.SubMatrix(m2);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            ASSERT_DOUBLE_EQ(m1(i, j), exp(i, j));
        }
    }
}

TEST(test_sub_matrix, one_by_one) {
    int rows = 1;
    int cols = 1;
    S21Matrix m1(rows, cols);
    S21Matrix m2(rows, cols);
    double exp = -1;

    m1(0, 0) = 7;
    m2(0, 0) = 8;

    m1.SubMatrix(m2);

    ASSERT_DOUBLE_EQ(m1(0, 0), exp);
}

TEST(test_sub_matrix, incorrect) {
    S21Matrix m1(3, 4);
    S21Matrix m2(4, 5);

    ASSERT_ANY_THROW(m1.SubMatrix(m2));
}
