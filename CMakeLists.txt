cmake_minimum_required(VERSION 3.14...3.26)
	
project(Cpp_Tools LANGUAGES CXX)

set(CMAKE_BUILD_TYPE Release)
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

enable_testing()

find_package(GTest REQUIRED)
find_package(NLopt)
find_package(SWIG)
find_package(nlohmann_json)

include(GoogleTest)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set global property (all targets are impacted)
set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE "${CMAKE_COMMAND} -E time")

include(CMakePrintHelpers)
cmake_print_variables(CMAKE_CXX_COMPILER_ID)
cmake_print_variables(CMAKE_CXX_COMPILER_VERSION)

configure_file(
    ${PROJECT_SOURCE_DIR}/tools/utils/CMAKE_config.h.in 
    ${PROJECT_SOURCE_DIR}/tools/utils/CMAKE_config.h
)


add_subdirectory(projectname)