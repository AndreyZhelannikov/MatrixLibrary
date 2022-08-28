#include <gtest/gtest.h>

#include "../s21_matrix_oop.h"

TEST(test_helpers_1, size) {
    S21Matrix m(4, 5);
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 5; ++j) {
            m(i, j) = i * 4 + j;
        }
    }

    ASSERT_EQ(m.GetRows(), 4);
    ASSERT_EQ(m.GetCols(), 5);
}

TEST(test_helpers_2, setsize) {
    S21Matrix m(2, 2);

    S21Matrix exp(3, 3);
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            m(i, j) = i * 2 + j;
            exp(i, j) = i * 2 + j;
        }
    }

    m.SetRows(3);

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 2; ++j) {
            ASSERT_DOUBLE_EQ(m(i, j), exp(i, j));
        }
    }

    m.SetCols(3);

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            ASSERT_DOUBLE_EQ(m(i, j), exp(i, j));
        }
    }
}
