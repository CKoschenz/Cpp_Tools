#include <algorithm>
#include <cmath>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <tools/utils/range.hpp>

/**
 * @brief Test integer range
 * 
 */
TEST(RangeTest, IntRange) {

  std::vector<int> true_range {3,4,5,6,7,8};

  std::vector<int> therange = op::range<int>(3,8,5);

  std::vector<int> diff(6);

  std::transform( therange.begin(), therange.end(), true_range.begin(), diff.begin(), 
    std::minus<int>());

  // float (*fabs)(float) = &std::abs;
  // std::transform(diff.begin(), diff.end(), diff.begin(), fabs);

  ASSERT_THAT(diff, testing::Each(testing::AllOf(testing::Eq(0))));
}
