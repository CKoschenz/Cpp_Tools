add_library(io)

#find_package(fmt)

target_sources(io
  PUBLIC
    io.hpp
  PRIVATE
    io.cpp
  )

#target_link_libraries(io fmt::fmt)

target_include_directories(io
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
  )
