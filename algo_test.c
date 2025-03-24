#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>
#include <CUnit/TestDB.h>
#include <CUnit/TestRun.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include "algo_lib.h"
#include "linked_list_int.h"
#include "linked_list_str.h"
#include "helpers.h"
#include "queue.h"
#include "ringBuffer.h"
#include "quick_sort.h"
#include "trees.h"



void PopulateList(LinkedList *list) {
    Append(list, "test 1");
    Append(list, "test 2");
    Append(list, "test 3");
    Append(list, "test 4");
    Append(list, "test 5");
}

void TestAppend(void) {
    LinkedList list = GetEmptyList();
    PopulateList(&list);
    CU_ASSERT(list.length == 5);
    CU_ASSERT(list.head != NULL);
    CU_ASSERT(strcmp(list.head->value, "test 1") == 0);
    CU_ASSERT(strcmp(list.head->next->next->next->next->value, "test 5") == 0);
    CU_ASSERT(list.head->next->next->next->next->next == NULL);
    Clear(&list);
}


void TestGetAt(void) {
    LinkedList list = GetEmptyList();
    PopulateList(&list);
    CU_ASSERT(strcmp(GetAt(&list, 0), "test 1") == 0);
    CU_ASSERT(strcmp(GetAt(&list, 1), "test 2") == 0);
    CU_ASSERT(strcmp(GetAt(&list, 4), "test 5") == 0);
    CU_ASSERT(GetAt(&list, 5) == NULL);
    Clear(&list);
}

void TestPrepend(void) {
    LinkedList list = GetEmptyList();
    PopulateList(&list);
    Prepend(&list, "test 6");
    Prepend(&list, "test 7");
    Prepend(&list, "test 8");
    Prepend(&list, "test 9");
    Prepend(&list, "test 10");
    CU_ASSERT(strcmp(GetAt(&list, 0), "test 10") == 0);
    CU_ASSERT(strcmp(GetAt(&list, 1), "test 9") == 0);
    CU_ASSERT(strcmp(GetAt(&list, 5), "test 1") == 0);
    CU_ASSERT(strcmp(GetAt(&list, 9), "test 5") == 0);
    CU_ASSERT(GetAt(&list, 10) == 0);
    CU_ASSERT(list.length == 10);
    Clear(&list);
}

void TestRemoveAt(void) {
    LinkedList list = GetEmptyList();
    PopulateList(&list);
    CU_ASSERT(strcmp(RemoveAt(&list, 0), "test 1") == 0);
    CU_ASSERT(list.length == 4);
    CU_ASSERT(strcmp(RemoveAt(&list, 3), "test 5") == 0);
    CU_ASSERT(strcmp(RemoveAt(&list, 2), "test 4") == 0);
    CU_ASSERT(strcmp(RemoveAt(&list, 0), "test 2") == 0);
    CU_ASSERT(list.length == 1);
    CU_ASSERT(strcmp(RemoveAt(&list, 0), "test 3") == 0);
    CU_ASSERT(list.length == 0);
    CU_ASSERT(RemoveAt(&list, 0) == 0);
    Clear(&list);
}

void TestRemoveFirst(void) {
    LinkedList list = GetEmptyList();
    PopulateList(&list);
    CU_ASSERT(strcmp(RemoveFirst(&list), "test 1") == 0);
    CU_ASSERT(strcmp(RemoveFirst(&list), "test 2") == 0);
    CU_ASSERT(list.length == 3);
    CU_ASSERT(strcmp(RemoveFirst(&list), "test 3") == 0);
    CU_ASSERT(strcmp(RemoveFirst(&list), "test 4") == 0);
    CU_ASSERT(list.length == 1);
    CU_ASSERT(strcmp(RemoveFirst(&list), "test 5") == 0);
    CU_ASSERT(list.length == 0);
    CU_ASSERT(RemoveFirst(&list) == 0);
    Clear(&list);
}

void TestRemoveLast(void) {
    LinkedList list = GetEmptyList();
    PopulateList(&list);
    CU_ASSERT(strcmp(RemoveLast(&list), "test 5") == 0);
    CU_ASSERT(strcmp(RemoveLast(&list), "test 4") == 0);
    CU_ASSERT(strcmp(RemoveLast(&list), "test 3") == 0);
    CU_ASSERT(strcmp(RemoveLast(&list), "test 2") == 0);
    CU_ASSERT(strcmp(RemoveLast(&list), "test 1") == 0);
    Clear(&list);
}


void TestClear(void) {
    LinkedList list = GetEmptyList();
    PopulateList(&list);
    Clear(&list);
    CU_ASSERT(list.length == 0);
    CU_ASSERT(list.head == NULL);
    CU_ASSERT(list.tail == NULL);
}

void TestLinkedList(CU_pSuite suite) {
    CU_add_test(suite, "Append", TestAppend);
    CU_add_test(suite, "GetAt", TestGetAt);
    CU_add_test(suite, "Prepend", TestPrepend);
    CU_add_test(suite, "RemoveAt", TestRemoveAt);
    CU_add_test(suite, "RemoveFirst", TestRemoveFirst);
    CU_add_test(suite, "RemoveLast", TestRemoveLast);
    CU_add_test(suite, "Clear", TestClear);
}

void TestStack(CU_pSuite suite) {

}

void TestQueue(void) {
    Queue list = GetQueue();

    EnQueue(&list, 5);
    EnQueue(&list, 7);
    EnQueue(&list, 9);

    CU_ASSERT(DeQueue(&list) == 5);
    CU_ASSERT(list.length == 2);

    EnQueue(&list, 11);
    CU_ASSERT(DeQueue(&list) == 7);
    CU_ASSERT(DeQueue(&list) == 9);
    CU_ASSERT(PeekQueue(&list) == 11);
    CU_ASSERT(DeQueue(&list) == 11);
    CU_ASSERT(DeQueue(&list) == 0);
    CU_ASSERT(list.length == 0);

    EnQueue(&list, 69);
    CU_ASSERT(PeekQueue(&list) == 69);
    CU_ASSERT(list.length == 1);
}

void TestRingBuffer(void) {
    RingBuffer buffer = GetRingBuffer(5);

    AddToStart(&buffer, 1);
    CU_ASSERT(PeekStart(&buffer) == 1);
    CU_ASSERT(PeekEnd(&buffer) == 1);
    CU_ASSERT(buffer.length == 1);

    AddToEnd(&buffer, 2);
    CU_ASSERT(PeekStart(&buffer) == 1);
    CU_ASSERT(PeekEnd(&buffer) == 2);
    CU_ASSERT(buffer.length == 2);

    AddToStart(&buffer, 3);
    CU_ASSERT(RemoveFromStart(&buffer) == 3);
    CU_ASSERT(RemoveFromEnd(&buffer) == 2);
    CU_ASSERT(PeekStart(&buffer) == 1);
    CU_ASSERT(PeekEnd(&buffer) == 1);

    PrintRingBuffer(&buffer);
    AddToStart(&buffer, 4);
    AddToStart(&buffer, 5);
    AddToStart(&buffer, 6);
    CU_ASSERT(buffer.length == 4);

    RemoveFromEnd(&buffer);
    RemoveFromEnd(&buffer);
    RemoveFromEnd(&buffer);
    AddToStart(&buffer, 7);
    AddToStart(&buffer, 9);
    AddToStart(&buffer, 9);
    PrintRingBuffer(&buffer);

    ClearBuffer(&buffer);
    PrintRingBuffer(&buffer);
    AddToEnd(&buffer, 1);
    AddToEnd(&buffer, 2);
    AddToEnd(&buffer, 3);
    AddToEnd(&buffer, 4);
    AddToEnd(&buffer, 5);
    PrintRingBuffer(&buffer);
    AddToEnd(&buffer, 6);
    PrintRingBuffer(&buffer);
    ClearBuffer(&buffer);
    free(buffer.heap_position);
}
bool CompareIntArrays(int *array1, int *array2, int length) {
    for (int i = 0; i < length; i++) {
        if (array1[i] != array2[i]) {
            printf("Arrays not equal: %d != %d at index %d\n", array1[i], array2[i], i);
            return false;
        }
    }
    return true;
}

void TestQuickSort(void) {
    int arr1[] = {1};
    int exp1[] = {1};
    QuickSort(arr1, 1);
    CU_ASSERT(CompareIntArrays(arr1, exp1, 1));

    int arr2[] = {1, 2};
    int exp2[] = {1, 2};
    QuickSort(arr2, 2);
    CU_ASSERT(CompareIntArrays(arr2, exp2, 2));

    int arr3[] = {2, 1};
    int exp3[] = {1, 2};
    QuickSort(arr3, 2);
    CU_ASSERT(CompareArrays(arr3, exp3, 2));

    int arr4[]= {2, 3, 8, 1, 7, 9, 5};
    int exp4[] = {1, 2, 3, 5, 7, 8, 9};
    QuickSort(arr4, 7); 
    CU_ASSERT(CompareArrays(arr4, exp4, 7));
}

void TestBinarytree(void) {
    BinaryNode *node1 = InitBinaryTree();
    BinaryNode *node2 = InitBinaryTree2();

    CU_ASSERT(NumChildren(node1) == 9);
    CU_ASSERT(NumChildren(node2) == 10);

    DoubleLinkedListInt storage1 = DLLIntGetEmptyList();
    /*int expected1[10] = {5, 7, 10, 15, 20, 29, 30, 45, 50, 100};*/
    DoubleLinkedListInt storage2 = DLLIntGetEmptyList();
    /*int expected2[11] = {5, 7, 10, 15, 20, 21, 29, 30, 45, 49, 51};*/

    PreOrderSearch(node1, &storage1);
    PreOrderSearch(node2, &storage2);

    /*CU_ASSERT(CompareIntArrays(sorted1, expected1, 10) == true);*/
    /*CU_ASSERT(CompareIntArrays(sorted2, expected2, 11) == true);*/
}

int main(void) {
    CU_initialize_registry();
    CU_pSuite suite = CU_add_suite("Sorting", 0, 0);
    TestLinkedList(suite);
    /*CU_add_test(suite, "Queue", TestQueue);*/
    /*CU_add_test(suite, "Ring Buffer", TestRingBuffer);*/
    CU_add_test(suite, "Quick Sort", TestQuickSort);
    CU_add_test(suite, "Binary Tree", TestBinarytree);
    TestStack(suite);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return 0;
}
