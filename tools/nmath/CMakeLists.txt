add_library(NMath)

target_sources(NMath
  PUBLIC
    combinatorics.hpp
    finite_differentiation.hpp
  PRIVATE
    combinatorics.cpp
    finite_differentiation.cpp
)

add_executable(
  TestNumericMath
  combinatorics.test.cpp
  finite_differentiation.test.cpp
)

target_link_libraries(
  TestNumericMath
  NMath
  GTest::gtest_main
)

gtest_discover_tests(TestNumericMath)
