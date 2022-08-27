#include <gtest/gtest.h>

#include "../s21_matrix_oop.h"

TEST(test_mult_number, normal) {
    int rows = 3;
    int cols = 3;
    double number = 5;
    S21Matrix m1(rows, cols);
    S21Matrix m2(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            m1(i, j) = i * cols + j;
            m2(i, j) = i * cols + j;
        }
    }
    m1.MulNumber(number);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            ASSERT_DOUBLE_EQ(m1(i, j), m2(i, j) * number);
        }
    }
}
