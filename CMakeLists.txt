cmake_minimum_required(VERSION 3.15)
project(algo_lib VERSION 1.0 LANGUAGES C)

# Set the C standard for C99
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_subdirectory(src)
add_subdirectory(test)

enable_testing()
