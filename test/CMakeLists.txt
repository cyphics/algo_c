# Add Unity framework
add_library(Unity 
  ../extern/Unity/src/unity.c
)

# set dir where all tests are located
set(TESTS_DIR ${CMAKE_SOURCE_DIR}/test)

# auto find all test .c files
file(GLOB TEST_FILES "${TESTS_DIR}/*.c")

message(STATUS "Found test files: ${TEST_FILES}")

# Add test exec
add_executable(UnitTests
  ./test_main.c
  ./test_linked_list.c
  ./test_binary_tree.c
  ./test_misc.c
  ./test_heap.c
)

set_target_properties(UnitTests PROPERTIES LINK_FLAGS -lcunit)

target_include_directories(UnitTests PRIVATE
  ../extern/Unity/src 
  ${CMAKE_SOURCE_DIR}/src # Include your library headers
)

# Link Unity and your library
target_link_libraries(UnitTests Unity algo)

enable_testing()
add_test(NAME UnitTests COMMAND UnitTests)
