#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>
#include <CUnit/TestDB.h>
#include <CUnit/TestRun.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include "algo_lib.h"
#include "helpers.h"
#include "queue.h"
#include "ringBuffer.h"
#include "quick_sort.h"
#include "trees.h"



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

    LinkedList storage1 = LinkedListGetEmptyList();
    /*int expected1[10] = {5, 7, 10, 15, 20, 29, 30, 45, 50, 100};*/
    LinkedList storage2 = LinkedListGetEmptyList();
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
    // CU_add_test(suite, "Quick Sort", TestQuickSort);
    // CU_add_test(suite, "Binary Tree", TestBinarytree);
    TestStack(suite);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return 0;
}
