#include <gtest/gtest.h>

#include "../s21_matrix_oop.h"

TEST(test_eq_matrix, nesize) {
    int rows = 4;
    int cols = 3;
    S21Matrix m1(rows, cols);
    S21Matrix m2(rows, cols);

    ASSERT_TRUE(m1.EqMatrix(m2));
}

TEST(test_eq_matrix, one_by_one) {
    int rows = 1;
    int cols = 1;
    S21Matrix m1(rows, cols);
    S21Matrix m2(rows, cols);

    ASSERT_TRUE(m1.EqMatrix(m2));
}

TEST(test_eq_matrix, nematrix) {
    int rows = 5;
    int cols = 3;
    S21Matrix m1(rows, cols - 1);
    S21Matrix m2(rows + 1, cols);

    ASSERT_FALSE(m1.EqMatrix(m2));
}

TEST(test_eq_matrix, nevalues) {
    int rows = 3;
    int cols = 4;
    S21Matrix m1(rows, cols);
    S21Matrix m2(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            m1(i, j) = i * cols + j;
            m2(i, j) = i * cols + j;
        }
    }
    m1(2, 2) = 5;
    ASSERT_FALSE(m1.EqMatrix(m2));
}
