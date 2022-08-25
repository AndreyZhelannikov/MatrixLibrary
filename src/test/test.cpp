#include <gtest/gtest.h>

#include "../s21_matrix_oop.h"

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
    S21Matrix m;
    std::cout << m.getCols() << ' ' << m.getRows() << std::endl;
    // Expect two strings not to be equal.
    // EXPECT_STRNE("hello", "world");
    // Expect equality.
    EXPECT_EQ(7 * 6, 42);
}