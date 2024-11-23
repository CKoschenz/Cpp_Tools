add_library(utils)

target_sources(utils
  PUBLIC
    utils.hpp
  PRIVATE
    utils.cpp
)

target_include_directories(utils
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)

add_executable(
  test_utils
  utils.test.cpp
)

target_link_libraries(
  test_utils
  utils
  GTest::gtest_main
)

gtest_discover_tests(test_utils)

add_library(range INTERFACE range.hpp)

target_include_directories(range
  INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}
)

add_executable(
  test_range
  range.test.cpp
)

target_link_libraries(
  test_range
  GTest::gtest_main
)

gtest_discover_tests(test_range)

add_library(indexer)

target_sources(indexer
  PUBLIC
    indexer.hpp
  PRIVATE
    indexer.cpp
)

target_include_directories(indexer
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)

add_executable(
  test_indexer
  indexer.test.cpp
)

target_link_libraries(
  test_indexer
  indexer
  GTest::gtest_main
)

gtest_discover_tests(test_indexer)