#include <gtest/gtest.h>

#include "../s21_matrix_oop.h"

TEST(test_calc_complements_1, normal) {
    S21Matrix m(3, 3);
    S21Matrix exp(3, 3);

    m(0, 0) = 1;
    m(0, 1) = 2;
    m(0, 2) = 3;

    m(1, 0) = 0;
    m(1, 1) = 4;
    m(1, 2) = 2;

    m(2, 0) = 5;
    m(2, 1) = 2;
    m(2, 2) = 1;

    exp(0, 0) = 0;
    exp(0, 1) = 10;
    exp(0, 2) = -20;

    exp(1, 0) = 4;
    exp(1, 1) = -14;
    exp(1, 2) = 8;

    exp(2, 0) = -8;
    exp(2, 1) = -2;
    exp(2, 2) = 4;

    S21Matrix res = m.CalcComplements();

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            ASSERT_DOUBLE_EQ(res(i, j), exp(i, j));
        }
    }
}

TEST(test_calc_complements_1, one_by_one) {
    S21Matrix m(1, 1);

    ASSERT_ANY_THROW(m.CalcComplements());
}
