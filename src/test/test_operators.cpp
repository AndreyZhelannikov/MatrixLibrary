#include <gtest/gtest.h>

#include "../s21_matrix_oop.h"

TEST(test_sum_operator, normal) {
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
            exp(i, j) = m1(i, j) + m2(i, j);
        }
    }

    S21Matrix res = m1 + m2;
    m1 += m2;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            ASSERT_DOUBLE_EQ(res(i, j), exp(i, j));
            ASSERT_DOUBLE_EQ(m1(i, j), exp(i, j));
        }
    }
}

TEST(test_min_operator, normal) {
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

    S21Matrix res = m1 - m2;
    m1 -= m2;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            ASSERT_DOUBLE_EQ(res(i, j), exp(i, j));
            ASSERT_DOUBLE_EQ(m1(i, j), exp(i, j));
        }
    }
}

TEST(test_mul_mat_operator, normal) {
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

    S21Matrix res = m1 * m2;
    m1 *= m2;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < rows; ++j) {
            ASSERT_DOUBLE_EQ(res(i, j), mul(i, j));
            ASSERT_DOUBLE_EQ(m1(i, j), mul(i, j));
        }
    }
}

TEST(test_eq_operator, nesize) {
    int rows = 4;
    int cols = 3;
    S21Matrix m1(rows, cols);
    S21Matrix m2(rows, cols);

    ASSERT_TRUE(m1 == m2);
}

TEST(test_const_getindex, out_of_range) {
    const S21Matrix m(1, 1);
    ASSERT_DOUBLE_EQ(m(0, 0), 0);
    ASSERT_ANY_THROW(m(69, 69));
}

TEST(test_getindex, out_of_range) {
    S21Matrix m(1, 1);
    ASSERT_DOUBLE_EQ(m(0, 0), 0);
    ASSERT_ANY_THROW(m(69, 69));
}

TEST(test_selfassign, self_assign) {
    S21Matrix m(1, 1);
    S21Matrix *p = &m;
    m = m;
    ASSERT_EQ(p, &m);
}

TEST(test_mult_number_operator, normal) {
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
    m1 *= number;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            ASSERT_DOUBLE_EQ(m1(i, j), m2(i, j) * number);
        }
    }
}

TEST(test_mult_number_operator, leftsize) {
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
    m1 = m1 * number;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            ASSERT_DOUBLE_EQ(m1(i, j), m2(i, j) * number);
        }
    }
}

TEST(test_mult_number_operator, rightside) {
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
    m1 = number * m1;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            ASSERT_DOUBLE_EQ(m1(i, j), m2(i, j) * number);
        }
    }
}