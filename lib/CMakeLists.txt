add_library(algo algo.c)

# state that anybody linking to us needs to include the current source dir
# to find MathFunctions.h, while we don't.
target_include_directories(algo
                           INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
                           )


