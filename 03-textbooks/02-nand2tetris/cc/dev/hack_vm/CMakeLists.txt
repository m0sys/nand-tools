cmake_minimum_required (VERSION 3.14)
project (hack_vm)

# TODO: separate test and src cmake configs into subdir configs.
# TODO: swap googletest with catch2.

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
# FIXME: replace this bad practice.
# NOTE: this glob stuff cannot detect new files since the generated build sys
#       will have a hardcoded list of source files at the time the build was
#       generated. Therefore, we are forced to rebuild the build sys in order
#       to get the new file. WE NEED TO FIX THIS.
file (GLOB source_files "${source_dir}/*.cc", "${source_dir}/*/*.cc")
file (GLOB test_files "${test_dir}/*.cc", "${test_dir}/*/*.cc")

set (main_exec hack_vm)
set (test_exec hack_vm_test)
add_executable (${main_exec} ${source_files})
add_executable (${test_exec} ${test_files})
add_library(${main_exec}_lib ${source_files})

# Cached values.
set (build_type Debug CACHE STRING "Build type")
set_property(CACHE build_type PROPERTY
    STRINGS Debug Release Dist
)

# GoogleTest setup.
enable_testing()
target_link_libraries(${test_exec}
    PUBLIC ${main_exec}_lib
    PRIVATE gtest_main
)

include(GoogleTest)
gtest_discover_tests(${test_exec})
