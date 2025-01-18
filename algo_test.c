#include "algo_lib.h"
#include "helpers.h"
#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>
#include <CUnit/TestDB.h>
#include <CUnit/TestRun.h>
#include <stdbool.h>
#include <stdint.h>

void foo(int i) {
    printf("%d", i);
}

void test_IndexOfSorted(void) {
    int foo[] = {1, 3, 4, 69, 71, 81, 90, 99, 420, 1337, 69420};
    int size = sizeof(foo) / sizeof(foo[0]);
    CU_ASSERT(IndexOfSorted(foo, 69, size) == 3);
    CU_ASSERT(IndexOfSorted(foo, 1336, size) == -1);
    CU_ASSERT(IndexOfSorted(foo, 69420, size) == 10);
    CU_ASSERT(IndexOfSorted(foo, 69421, size) == -1);
    CU_ASSERT(IndexOfSorted(foo, 1, size) == 0);
    CU_ASSERT(IndexOfSorted(foo, 0, size) == -1);
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
            IndexOf(&target1, &array, sizeof(array), sizeof(target1));
    int index2 =
            IndexOf(&target2, &array, sizeof(array), sizeof(target2));
    CU_ASSERT(index1 == 2);
    CU_ASSERT(index2 == -1);

    double double1 = 0.1;
    double double2 = 0.2;
    double array2[] = {0.2, 3.98, 38924.9, 0.0};

    index1 = IndexOf(&double1, &array2, sizeof(array2), sizeof(double1));
    index2 = IndexOf(&double2, &array2, sizeof(array2), sizeof(double2));
    CU_ASSERT(index1 == -1);
    CU_ASSERT(index2 == 0);
}

void test_BubbleSort(void) {
    int arr[] = {10, 9, 3, 7, 4, 69, 420, 42, 41};
    int sorted[] = {3, 4, 7, 9, 10, 41, 42, 69, 420};

    int size = sizeof(arr) / sizeof(arr[0]);
    BubbleSort(arr, size);

    CU_ASSERT(CompareArrays(arr, sorted, sizeof(arr)));
}


// Receives an empty list and populates it
void SLLPopulateList(SingleLinkedList *list) {
    SLLAppend(list, 1);
    SLLAppend(list, 2);
    SLLAppend(list, 3);
    SLLAppend(list, 4);
    SLLAppend(list, 5);
}
void TestSLLAppend(void) {
    SingleLinkedList list = SLLGetEmptyList();
    SLLPopulateList(&list);
    CU_ASSERT(list.head->value = 1);
    CU_ASSERT(list.head->next->next->next->next->value == 5);
    CU_ASSERT(list.head->next->next->next->next->next == NULL);
    CU_ASSERT(list.length = 5);
    SLLClear(&list);
}

void TestSLLGetAt(void) {
    SingleLinkedList list = SLLGetEmptyList();
    SLLPopulateList(&list);
    CU_ASSERT(SLLGetAt(&list, 0) == 1);
    CU_ASSERT(SLLGetAt(&list, 1) == 2);
    CU_ASSERT(SLLGetAt(&list, 4) == 5);
    CU_ASSERT(SLLGetAt(&list, 5) == 0);
    SLLClear(&list);
}

void TestSLLPrepend(void) {
    SingleLinkedList list = SLLGetEmptyList();
    SLLPrepend(&list, 1);
    SLLPrepend(&list, 2);
    SLLPrepend(&list, 3);
    SLLPrepend(&list, 4);
    SLLPrepend(&list, 5);
    CU_ASSERT(SLLGetAt(&list, 0) == 5);
    CU_ASSERT(SLLGetAt(&list, 4) == 1);
    SLLClear(&list);
}

void TestSLLRemoveAt(void) {
    SingleLinkedList list = SLLGetEmptyList();
    SLLPopulateList(&list);
    CU_ASSERT(SLLRemoveAt(&list, 0) == 1);
    CU_ASSERT(list.length == 4);
    CU_ASSERT(SLLRemoveAt(&list, 3) == 5);
    CU_ASSERT(list.length == 3);
    SLLClear(&list);
}

void TestSingleLinkedList(CU_pSuite suite) {
    CU_add_test(suite, "SLLAppend", TestSLLAppend);
    CU_add_test(suite, "SLLGetAt", TestSLLGetAt);
    CU_add_test(suite, "SLLPrepend", TestSLLPrepend);
    CU_add_test(suite, "SLLRemoveAt", TestSLLRemoveAt);
}

void DLLPopulateList(DoubleLinkedList *list) {
    DLLAppend(list, 1);
    DLLAppend(list, 2);
    DLLAppend(list, 3);
    DLLAppend(list, 4);
    DLLAppend(list, 5);
}

void TestDLLAppend(void) {
    DoubleLinkedList list = DLLGetEmptyList();
    DLLPopulateList(&list);
    CU_ASSERT(list.length == 5);
    CU_ASSERT(list.head != NULL);
    CU_ASSERT(list.head->value == 1);
    CU_ASSERT(list.head->next->next->next->next->value == 5);
    CU_ASSERT(list.head->next->next->next->next->next == NULL);
    DLLClear(&list);
}


void TestDLLGetAt(void) {
    DoubleLinkedList list = DLLGetEmptyList();
    DLLPopulateList(&list);
    CU_ASSERT(DLLGetAt(&list, 0) == 1);
    CU_ASSERT(DLLGetAt(&list, 4) == 5);
    CU_ASSERT(DLLGetAt(&list, 5) == 0);
    DLLClear(&list);
}

void TestDLLPrepend(void) {
    DoubleLinkedList list = DLLGetEmptyList();
    DLLPopulateList(&list);
    DLLPrepend(&list, 6);
    DLLPrepend(&list, 7);
    DLLPrepend(&list, 8);
    DLLPrepend(&list, 9);
    DLLPrepend(&list, 10);
    CU_ASSERT(DLLGetAt(&list, 0) == 10);
    CU_ASSERT(DLLGetAt(&list, 1) == 9);
    CU_ASSERT(DLLGetAt(&list, 5) == 1);
    CU_ASSERT(DLLGetAt(&list, 9) == 5);
    CU_ASSERT(DLLGetAt(&list, 10) == 0);
    CU_ASSERT(list.length == 10);
    DLLClear(&list);
}

void TestDLLRemoveFirst(void) {
    DoubleLinkedList list = DLLGetEmptyList();
    DLLPopulateList(&list);
    CU_ASSERT(DLLRemoveFirst(&list) == 1);
    CU_ASSERT(DLLRemoveFirst(&list) == 2);
    CU_ASSERT(list.length == 3);
    CU_ASSERT(DLLRemoveFirst(&list) == 3);
    CU_ASSERT(DLLRemoveFirst(&list) == 4);
    CU_ASSERT(list.length == 1);
    CU_ASSERT(DLLRemoveFirst(&list) == 5);
    CU_ASSERT(list.length == 0);
    CU_ASSERT(DLLRemoveFirst(&list) == 0);
    DLLClear(&list);
}

void TestDLLRemoveLast(void) {
    DoubleLinkedList list = DLLGetEmptyList();
    DLLPopulateList(&list);
    CU_ASSERT(DLLRemoveLast(&list) == 5);
    DLLClear(&list);
}

void TestDLLRemoveAt(void) {
    DoubleLinkedList list = DLLGetEmptyList();
    DLLPopulateList(&list);
    CU_ASSERT(DLLRemoveAt(&list, 0) == 1);
    CU_ASSERT(list.length == 4);
    CU_ASSERT(DLLRemoveAt(&list, 3) == 5);
    CU_ASSERT(DLLRemoveAt(&list, 4) == 0);
    CU_ASSERT(DLLRemoveAt(&list, 0) == 2);
    CU_ASSERT(list.length == 2);
    CU_ASSERT(DLLRemoveAt(&list, 0) == 3);
    CU_ASSERT(DLLRemoveAt(&list, 0) == 4);
    CU_ASSERT(DLLRemoveAt(&list, 0) == 0);
    DLLClear(&list);
}

void TestDLLClear(void) {
    DoubleLinkedList list = DLLGetEmptyList();
    DLLPopulateList(&list);
    DLLClear(&list);
    CU_ASSERT(list.length == 0);
    CU_ASSERT(list.head == NULL);
    CU_ASSERT(list.tail == NULL);
}

void TestDoubleLinkedList(CU_pSuite suite) {
    CU_add_test(suite, "DLLAppend", TestDLLAppend);
    CU_add_test(suite, "DLLGetAt", TestDLLGetAt);
    CU_add_test(suite, "DLLPrepend", TestDLLPrepend);
    CU_add_test(suite, "DLLRemoveAt", TestDLLRemoveAt);
    CU_add_test(suite, "DLLClear", TestDLLClear);
}

int main(void) {
    CU_initialize_registry();
    CU_pSuite suite = CU_add_suite("Sorting", 0, 0);
    CU_add_test(suite, "IndexOf", test_IndexOf);
    CU_add_test(suite, "IndexOfSorted", test_IndexOfSorted);
    CU_add_test(suite, "BubbleSort", test_BubbleSort);
    CU_add_test(suite, "Sorting", test_sorting);
    TestSingleLinkedList(suite);
    TestDoubleLinkedList(suite);
    CU_basic_run_tests();
    CU_cleanup_registry();
    /*TestSegFault();*/
    return 0;
}
