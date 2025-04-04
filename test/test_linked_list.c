#include "../linked_list.h"
#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>
#include <CUnit/TestDB.h>
#include <CUnit/TestRun.h>
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
    struct LLNode *current = l->head;
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
    LinkedListPrepend(&list, "test 10", size);
    test_equal_str(LinkedListGetAt(&list, 0), "test 10");
    test_equal_str(LinkedListGetAt(&list, 1), "test 9");
    test_equal_str(LinkedListGetAt(&list, 5), "test 1");
    test_equal_str(LinkedListGetAt(&list, 9), "test 5");
    CU_ASSERT(LinkedListGetAt(&list, 10) == 0);
    CU_ASSERT(list.length == 10);
    LinkedListClear(&list);
}

void TestRemoveAt(void) {
    LinkedList list = LinkedListGetEmptyList();
    PopulateList(&list);
    test_equal_str(LinkedListRemoveAt(&list, 0), "test 1");
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
    LinkedListClear(&list);
}

void TestRemoveFirst(void) {
    LinkedList list = LinkedListGetEmptyList();
    PopulateList(&list);

    test_equal_str(LinkedListGetAt(&list, 0), "test 1");
    LinkedListRemoveFirst(&list);
    test_equal_str(LinkedListGetAt(&list, 0), "test 2");
    LinkedListRemoveFirst(&list);
    LinkedListRemoveFirst(&list);
    LinkedListRemoveFirst(&list);
    test_equal_str(LinkedListGetAt(&list, 0), "test 5");
    LinkedListRemoveFirst(&list);
    LinkedListRemoveFirst(&list);
    CU_ASSERT(list.head == NULL);
    // LinkedListClear(&list);
}

void TestLinkedListRemoveLast(void) {
    LinkedList list = LinkedListGetEmptyList();
    PopulateList(&list);
    test_equal_str(LinkedListRemoveLast(&list), "test 5");
    test_equal_str(LinkedListRemoveLast(&list), "test 4");
    test_equal_str(LinkedListRemoveLast(&list), "test 3");
    test_equal_str(LinkedListRemoveLast(&list), "test 2");
    test_equal_str(LinkedListRemoveLast(&list), "test 1");
    LinkedListClear(&list);
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
    CU_add_test(suite, "LinkedListRemoveFirst", TestRemoveFirst);
    //CU_add_test(suite, "LinkedListRemoveLast", TestLinkedListRemoveLast);
    //CU_add_test(suite, "LinkedListRemoveAt", TestRemoveAt);
    CU_add_test(suite, "Clear", TestClear);
}

