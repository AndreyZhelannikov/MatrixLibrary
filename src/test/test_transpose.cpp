#include <gtest/gtest.h>

#include "../s21_matrix_oop.h"

TEST(test_transpose, name) {
    int rows = 2;
    int cols = 4;
    S21Matrix m(rows, cols);
    S21Matrix t(cols, rows);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            m(i, j) = i * cols + j;
            t(j, i) = i * cols + j;
        }
    }
    S21Matrix res = m.Transpose();

    for (int i = 0; i < cols; ++i) {
        for (int j = 0; j < rows; ++j) {
            ASSERT_DOUBLE_EQ(res(i, j), t(i, j));
        }
    }
}
