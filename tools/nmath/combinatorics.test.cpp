#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <vanderwaals/nmath/combinatorics.hpp>

TEST(Numerics, BinomialCoefficient) {
  EXPECT_EQ(Binomial::getCoefficient(5,2), 10);
}

TEST(Numerics, AllBinomialCoefficients) {
  EXPECT_THAT(Binomial::getAllCoefficients(5), 
              testing::ElementsAre(1,5,10,10,5,1));
}

TEST(Numerics, KBinomialCoefficients) {
  EXPECT_THAT(Binomial::getKCoefficients(5,3), 
              testing::ElementsAre(1,5,10,10));
}

// Tests factorial of 0.
TEST(Numerics, FactorialHandlesZeroInput) {
  EXPECT_EQ(factorial(0), 1);
}

// Tests factorial of positive numbers.
TEST(Numerics, FactorialHandlesPositiveInput) {
  EXPECT_EQ(factorial(1), 1);
  EXPECT_EQ(factorial(2), 2);
  EXPECT_EQ(factorial(3), 6);
  EXPECT_EQ(factorial(8), 40320);
}