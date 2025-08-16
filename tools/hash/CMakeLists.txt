include_directories(${PROJECT_SOURCE_DIR})
add_executable(hash.x main.cpp)

add_library(hash INTERFACE hash.hpp)

target_sources(hash
  INTERFACE
    hash.hpp
)

target_include_directories(hash
  INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}
)

add_executable(
  hash_test
  hash.test.cpp
)

target_link_libraries(
  hash_test
  hash
  GTest::gtest_main
)

gtest_discover_tests(hash_test)
