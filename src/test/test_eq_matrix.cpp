#include <gtest/gtest.h>

#include "../s21_matrix_oop.h"

TEST(test_eq_matrix_1, nesize) {
    int rows = 4;
    int cols = 3;
    S21Matrix m1(rows, cols);
    S21Matrix m2(rows, cols);

    ASSERT_TRUE(m1.EqMatrix(m2));
}

TEST(test_eq_matrix_2, one_by_one) {
    int rows = 1;
    int cols = 1;
    S21Matrix m1(rows, cols);
    S21Matrix m2(rows, cols);

    ASSERT_TRUE(m1.EqMatrix(m2));
}

TEST(test_eq_matrix_3, nematrix) {
    int rows = 5;
    int cols = 3;
    S21Matrix m1(rows, cols - 1);
    S21Matrix m2(rows + 1, cols);

    ASSERT_FALSE(m1.EqMatrix(m2));
}