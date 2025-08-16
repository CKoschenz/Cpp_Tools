#include <gtest/gtest.h>

#include <tools/hash/hash.hpp>

TEST(HashTest, BasicAssertions) {
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
}

TEST(HashTest, FactorialTest) {
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
}