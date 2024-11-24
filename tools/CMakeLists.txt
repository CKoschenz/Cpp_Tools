add_executable(tools.x main.cpp)

include_directories(${PROJECT_SOURCE_DIR})

add_subdirectory(dependency_injection)
add_subdirectory(io)
add_subdirectory(factorial)
add_subdirectory(greeting)
add_subdirectory(parser)
add_subdirectory(utils)

target_link_libraries(tools.x
  PRIVATE
    greeting
    factorial
    io
    parser
)

target_include_directories(tools.x
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
  )


set_target_properties(tools.x
  PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}"
)