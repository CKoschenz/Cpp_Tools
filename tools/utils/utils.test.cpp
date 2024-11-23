#include <gtest/gtest.h>
#include <vanderwaals/utils/utils.hpp>

TEST(Utils, Min_of) {
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
}