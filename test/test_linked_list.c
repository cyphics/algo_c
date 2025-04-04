#include "../linked_list.h"
#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>
#include <CUnit/TestDB.h>
#include <CUnit/TestRun.h>
#include <stdlib.h>
#include "unittest_helpers.h"


void PopulateList(LinkedList *list) {
    int size = sizeof("test 1");
    LinkedListAppend(list, "test 1", size);
    LinkedListAppend(list, "test 2", size);
    LinkedListAppend(list, "test 3", size);
    LinkedListAppend(list, "test 4", size);
    LinkedListAppend(list, "test 5", size);
}

void DebugPrintList(LinkedList *l) {
    struct Node *current = l->head;
    int counter = 0;
    while (current != NULL && counter < 10) {
        printf("Node %i: %s\n", counter, (char*)current->data);
        current = current->next;
        counter++;
    }
}

void TestAppend(void) {
    LinkedList list = LinkedListGetEmptyList();
    PopulateList(&list);
    CU_ASSERT(list.length == 5);
    CU_ASSERT(list.head != NULL);
    test_equal_data(list.head->data, "test 1", sizeof("test 1"));
    test_equal_str(list.head->data, "test 1");
    test_equal_str(list.head->data, "test 1");
    test_equal_str(list.head->next->next->next->next->data, "test 5");
    CU_ASSERT(list.head->next->next->next->next->next == NULL);
    LinkedListClear(&list);
}

void TestClearList(void) {
    LinkedList l = LinkedListGetEmptyList();
    PopulateList(&l);
    LinkedListClear(&l);
}

void TestGetAt(void) {
    LinkedList list = LinkedListGetEmptyList();
    PopulateList(&list);
    test_equal_str(LinkedListGetAt(&list, 0), "test 1");
    test_equal_str(LinkedListGetAt(&list, 1), "test 2");
    test_equal_str(LinkedListGetAt(&list, 4), "test 5");
    CU_ASSERT(LinkedListGetAt(&list, 5) == NULL);
    LinkedListClear(&list);
}

void TestPrepend(void) {
    LinkedList list = LinkedListGetEmptyList();
    PopulateList(&list);
    int size = sizeof("test 1");
    LinkedListPrepend(&list, "test 6", size);
    LinkedListPrepend(&list, "test 7", size);
    LinkedListPrepend(&list, "test 8", size);
    LinkedListPrepend(&list, "test 9", size);
    LinkedListPrepend(&list, "test 10", size + 1);
    test_equal_str(LinkedListGetAt(&list, 0), "test 10");
    test_equal_str(LinkedListGetAt(&list, 1), "test 9");
    test_equal_str(LinkedListGetAt(&list, 5), "test 1");
    test_equal_str(LinkedListGetAt(&list, 9), "test 5");
    CU_ASSERT(LinkedListGetAt(&list, 10) == 0);
    CU_ASSERT(list.length == 10);
    LinkedListClear(&list);
}

void TestPopFirst(void) {
    LinkedList list = LinkedListGetEmptyList();
    PopulateList(&list);
    for (int i = 0; i < 5; i++) {
        void* result = LinkedListPopFirst(&list);
        char expected[7];
        snprintf(expected, sizeof("test 1"), "test %i", i+1);
        test_equal_str(result, expected);
        free(result);
    }
    CU_ASSERT(LinkedListPopFirst(&list) == NULL);
}

void TestLinkedListPopLast(void) {
    LinkedList list = LinkedListGetEmptyList();
    PopulateList(&list);
    for (int i = 0; i < 5; i++) {
        void* result = LinkedListPopLast(&list);
        printf("res: %s", result);
        char expected[7];
        snprintf(expected, sizeof("test 1"), "test %i", 5-i);
        test_equal_str(result, expected);
        free(result);
    }
    LinkedListClear(&list);
}

void TestPopAt(void) {
    LinkedList list = LinkedListGetEmptyList();
    PopulateList(&list);
    test_equal_str(LinkedListPopAt(&list, 3), "test 4");
    test_equal_str(LinkedListPopAt(&list, 0), "test 1");
    test_equal_str(LinkedListPopAt(&list, 3), "test 3");
    test_equal_str(LinkedListPopAt(&list, 1), "test 5");
    test_equal_str(LinkedListPopAt(&list, 0), "test 2");
    test_equal_str(LinkedListPopAt(&list, 0), "test 1");
    // test_equal_str(LinkedListRemoveAt(&list, 0), "test 2");
    // test_equal_str(LinkedListRemoveAt(&list, 0), "test 3");
    // test_equal_str(LinkedListRemoveAt(&list, 0), "test 4");
    // test_equal_str(LinkedListRemoveAt(&list, 0), "test 5");
    // CU_ASSERT(list.length;
    // test_equal_str(LinkedListRemoveAt(&list, 3), "test 5");
    // test_equal_str(LinkedListRemoveAt(&list, 2), "test 4");
    // test_equal_str(LinkedListRemoveAt(&list, 0), "test 2");
    // CU_ASSERT(list.length == 1);
    // test_equal_str(LinkedListRemoveAt(&list, 0), "test 3");
    // CU_ASSERT(list.length;
    // CU_ASSERT(LinkedListRemoveAt(&list, 0);
}

void TestClear(void) {
    LinkedList list = LinkedListGetEmptyList();
    PopulateList(&list);
    LinkedListClear(&list);
    CU_ASSERT(list.length == 0);
    CU_ASSERT(list.head == NULL);
    CU_ASSERT(list.tail == NULL);
}

void TestLinkedList(CU_pSuite suite) {
    CU_add_test(suite, "Append", TestAppend);
    CU_add_test(suite, "Clear", TestClearList);
    CU_add_test(suite, "GetAt", TestGetAt);
    CU_add_test(suite, "Prepend", TestPrepend);
    CU_add_test(suite, "LinkedListPopFirst", TestPopFirst);
    CU_add_test(suite, "LinkedListPopLast", TestLinkedListPopLast);
    CU_add_test(suite, "LinkedListPopAt", TestPopAt);
    CU_add_test(suite, "Clear", TestClear);
}

