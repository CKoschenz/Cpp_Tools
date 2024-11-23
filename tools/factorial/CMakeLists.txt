add_library(factorial)

target_sources(factorial
  PUBLIC
    factorial.hpp
  PRIVATE
    factorial.cpp
  )

add_executable(
  hello_test
  factorial.test.cpp
)

target_link_libraries(
  hello_test
  factorial
  GTest::gtest_main
)

gtest_discover_tests(hello_test)
