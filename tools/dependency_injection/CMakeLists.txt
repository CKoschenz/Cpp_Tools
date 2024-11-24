add_library(dependency INTERFACE dependency.hpp)

target_include_directories(dependency
  INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}
)

target_compile_options(dependency  
  INTERFACE
    -fconcepts
)

add_executable(dependency_injection.x main.cpp)

target_link_libraries(dependency_injection.x
  PUBLIC
    dependency
)

target_include_directories(dependency_injection.x
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)