add_library(greeting)

target_sources(greeting
  PUBLIC
    greeting.hpp
  PRIVATE
    greeting.cpp
  )