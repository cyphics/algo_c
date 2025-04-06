# Add Unity framework
add_library(Unity 
  ../extern/Unity/src/unity.c
)

# Add test exec
add_executable(UnitTests
  ./test_main.c
  # ./algo_test.c
  # ./test_linked_list.c
)

target_include_directories(UnitTests PRIVATE
  ../extern/Unity/src 
  ${CMAKE_SOURCE_DIR}/src # Include your library headers
)

# Link Unity and your library
target_link_libraries(UnitTests Unity algo)

enable_testing()
add_test(NAME UnitTests COMMAND UnitTests)
