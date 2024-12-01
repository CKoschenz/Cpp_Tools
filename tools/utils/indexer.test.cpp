#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <algorithm>
#include <cmath>
#include <tools/utils/indexer.hpp>

/**
 * @brief Test indexer
 *
 */
TEST(IndexerTest, ThreeIndex) {
  op::Indexer index({3, 7, 2});

  ASSERT_THAT(index({0, 0, 0}), 0);
  ASSERT_THAT(index({0, 0, 1}), 1);
  ASSERT_THAT(index({0, 1, 0}), 2);
  ASSERT_THAT(index({0, 1, 1}), 3);
  ASSERT_THAT(index({1, 0, 0}), 2 * 7);
  ASSERT_THAT(index({2, 0, 0}), 2 * 2 * 7);
  ASSERT_THAT(index({1, 1, 0}), 2 * 7 + 2);
  ASSERT_THAT(index({1, 1, 1}), 2 * 7 + 2 + 1);
}
