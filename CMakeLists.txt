cmake_minimum_required(VERSION 3.15)
project(algo_lib VERSION 1.0)

set(CMAKE_CXX_FLAGS_DEBUG_INIT "-fstack-protector")

add_library(algo_lib algo_lib.c helpers.c)

# state that anybody linking to us needs to include the current source dir
# to find MathFunctions.h, while we don't.
target_include_directories(algo_lib
                           INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
                           )

add_executable(algo_test algo_test.c)
target_link_libraries(algo_test PUBLIC algo_lib)
set_target_properties(algo_test PROPERTIES LINK_FLAGS -lcunit)

target_include_directories(algo_lib PUBLIC "${PROJECT_BINARY_DIR}")
