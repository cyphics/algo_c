cmake_minimum_required(VERSION 3.15)

# set the project name and version
project(Algorithms VERSION 1.0)

# add the MathFunctions library
add_subdirectory(lib)

# add the executable
add_executable(algorithms main.c)

target_link_libraries(algorithms PUBLIC algo)

# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
target_include_directories(algorithms PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )

