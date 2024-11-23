add_executable(automata.x main.cpp)

include_directories(${PROJECT_SOURCE_DIR})

add_subdirectory(io)
add_subdirectory(factorial)
add_subdirectory(greeting)
add_subdirectory(parser)

target_link_libraries(automata.x
  PRIVATE
    greeting
    factorial
    io
    parser
)

target_include_directories(automata.x
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
  )


set_target_properties(automata.x
  PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}"
)