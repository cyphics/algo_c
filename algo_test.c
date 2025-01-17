#include "algo_lib.h"
#include "helpers.h"
#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>
#include <stdbool.h>
#include <stdint.h>

void foo(int i) {
  printf("%d", i);
}

void test_IndexOfSorted(void) {
  int foo[] = {1, 3, 4, 69, 71, 81, 90, 99, 420, 1337, 69420};
  int size = sizeof(foo) / sizeof(foo[0]);
  CU_ASSERT(Sorting.IndexOfSorted(foo, 69, size) == 3);
  CU_ASSERT(Sorting.IndexOfSorted(foo, 1336, size) == -1);
  CU_ASSERT(Sorting.IndexOfSorted(foo, 69420, size) == 10);
  CU_ASSERT(Sorting.IndexOfSorted(foo, 69421, size) == -1);
  CU_ASSERT(Sorting.IndexOfSorted(foo, 1, size) == 0);
  CU_ASSERT(Sorting.IndexOfSorted(foo, 0, size) == -1);
}

void test_sorting(void) {
  /*int array[] = {1, 2, 4, 5, 7};*/
  /*CU_ASSERT(Sorting.BinarySearch(5, array, 5));*/
}

void test_IndexOf(void) {
  char target1 = 'c';
  char target2 = 'z';
  char array[] = {'a', 'b', 'c', 'd', 'e'};
  int index1 =
      Sorting.IndexOf(&target1, &array, sizeof(array), sizeof(target1));
  int index2 =
      Sorting.IndexOf(&target2, &array, sizeof(array), sizeof(target2));
  CU_ASSERT(index1 == 2);
  CU_ASSERT(index2 == -1);

  double double1 = 0.1;
  double double2 = 0.2;
  double array2[] = {0.2, 3.98, 38924.9, 0.0};

  index1 = Sorting.IndexOf(&double1, &array2, sizeof(array2), sizeof(double1));
  index2 = Sorting.IndexOf(&double2, &array2, sizeof(array2), sizeof(double2));
  CU_ASSERT(index1 == -1);
  CU_ASSERT(index2 == 0);
}

void test_BubbleSort(void) {
  int arr[] = {10, 9, 3, 7, 4, 69, 420, 42, 41};
  int sorted[] = {3, 4, 7, 9, 10, 41, 42, 69, 420};

  int size = sizeof(arr) / sizeof(arr[0]);
  Sorting.BubbleSort(arr, size);

  CU_ASSERT(CompareArrays(arr, sorted, sizeof(arr)));
}

void test_SingleLinkedList(void) {
  struct SingleLinkedList list;
  SLLInitialize(&list);

  SLLAppend(&list, 5);
  SLLAppend(&list, 7);
  SLLAppend(&list, 9);

  CU_ASSERT(SLLGetAt(&list, 0) == 5);
  CU_ASSERT(SLLGetAt(&list, 1) == 7);
  CU_ASSERT(SLLGetAt(&list, 2) == 9);
  CU_ASSERT(SLLRemoveAt(&list, 2) == 9);
  CU_ASSERT(SLLGetAt(&list, 2) == 0);
  CU_ASSERT(list.length == 2);

  SLLAppend(&list, 11);
  CU_ASSERT(SLLRemoveAt(&list, 1) == 7);
  CU_ASSERT(!SLLRemove(&list, 9));
  CU_ASSERT(SLLGetAt(&list, 2) == 0);
  CU_ASSERT(SLLRemoveAt(&list, 0) == 5);
  CU_ASSERT(SLLRemoveAt(&list, 0) == 11);
  CU_ASSERT(list.length == 0);

  SLLPrepend(&list, 5);
  SLLPrepend(&list, 7);
  SLLPrepend(&list, 9);

  CU_ASSERT(SLLGetLast(&list) == 9);

  CU_ASSERT(SLLGetAt(&list, 2) == 5);
  CU_ASSERT(SLLGetAt(&list, 1) == 7);
  CU_ASSERT(SLLGetAt(&list, 0) == 9);
  CU_ASSERT(SLLRemove(&list, 9));
  CU_ASSERT(list.length == 2);
  CU_ASSERT(SLLRemoveAt(&list, 9) == 0);

  SLLClear(&list);
  CU_ASSERT(list.length == 0);


}

void TestPrint(void) {
  struct SingleLinkedList list;
  SLLPrint(&list);
  SLLInitialize(&list);
  SLLPrint(&list);
  SLLAppend(&list, 3);
  SLLPrint(&list);
  SLLAppend(&list, 4);
  SLLAppend(&list, 5);
  SLLPrint(&list);
  SLLRemoveAt(&list, 0);
  SLLPrint(&list);
  SLLClear(&list);
  SLLPrint(&list);
}

int main(void) {
  CU_initialize_registry();
  CU_pSuite suite = CU_add_suite("Sorting", 0, 0);
  CU_add_test(suite, "IndexOf", test_IndexOf);
  CU_add_test(suite, "IndexOfSorted", test_IndexOfSorted);
  CU_add_test(suite, "BubbleSort", test_BubbleSort);
  CU_add_test(suite, "SingleLinkedList", test_SingleLinkedList);
  CU_add_test(suite, "Sorting", test_sorting);
  CU_basic_run_tests();
  CU_cleanup_registry();
  /*TestPrint();*/
  return 0;
}
