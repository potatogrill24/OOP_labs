#include <gtest/gtest.h>
#include "func.h"

TEST(test_01, basic_test_set) {
    ASSERT_TRUE(checkBr("()"));
}

TEST(test_02, basic_test_set) {
    ASSERT_FALSE(checkBr("()()(()"));
}

TEST(test_03, basic_test_set) {
    ASSERT_TRUE(checkBr("()()()((()))()"));
}

TEST(test_04_basic_test_set_Test, basic_test_set) {
    ASSERT_TRUE(checkBr("\0"));
}

TEST(test_05, basic_test_set) {
    ASSERT_FALSE(checkBr("("));
}

TEST(test_06, basic_test_set) {
    ASSERT_FALSE(checkBr(")"));
}

TEST(test_07, basic_test_set) {
    ASSERT_TRUE(checkBr("((((((()))))))"));
}

TEST(test_08, basic_test_set) {
    ASSERT_FALSE(checkBr("qwrqwrhqwurhqwurh"));
}

int main (int args, char **argv) {
    testing::InitGoogleTest(&args, argv);
    return RUN_ALL_TESTS();
}