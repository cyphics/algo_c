add_library(
  algo STATIC
  ./algorithms.c
  ./binary_tree.c
  ./helpers.c
  ./linked_list.c
  ./queue.c
  ./quick_sort.c
  ./ringBuffer.c
  ./sorting.c
)

target_include_directories(algo PUBLIC ${CMAKE_SOURCE_DIR}/include)

