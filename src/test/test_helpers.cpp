#include <gtest/gtest.h>

#include "../s21_matrix_oop.h"

TEST(test_helpers_1, size) {
    S21Matrix m(5, 5);
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            m(i, j) = i * m.GetCols() + j;
        }
    }
    // m.PrintMatrix();
    // m.SetSize(6, 7);
    // m.PrintMatrix();
    // m.SetSize(3, 3);
    // m.PrintMatrix();
    // ASSERT_TRUE(true);
}