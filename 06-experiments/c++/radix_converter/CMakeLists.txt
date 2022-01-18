cmake_minimum_required (VERSION 3.10)

project (radix_converter)

# This are variables.
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++17")
set (source_dir "${PROJECT_SOURCE_DIR}/src/")

# Which files that we compile.
file (GLOB source_files "${source_dir}/*.cc", "${source_dir}/*/*.cc")

add_executable (${PROJECT_NAME} ${source_files})
