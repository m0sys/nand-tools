cmake_minimum_required (VERSION 3.14)
project (hack_assembler)

# Declare dependencies.
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/3e0e32ba300ce8afe695ad3ba7e81b21b7cf237a.zip
)
FetchContent_MakeAvailable(googletest)

# Project variables.
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++17")
set (source_dir "${PROJECT_SOURCE_DIR}/src/")
set (test_dir "${PROJECT_SOURCE_DIR}/test/")

# Which files that we compile.
file (GLOB source_files "${source_dir}/*.cc")
file (GLOB test_files "${test_dir}/*.cc")

add_executable (${PROJECT_NAME} ${source_files})
add_executable (${PROJECT_NAME}_test ${test_files})
add_library(${PROJECT_NAME}_lib STATIC ${source_files})

# GoogleTest setup.
enable_testing()
target_link_libraries(
    ${PROJECT_NAME}_test PUBLIC
    ${PROJECT_NAME}_lib
    gtest_main
)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME}_test)
