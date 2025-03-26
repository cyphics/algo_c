#include "linked_list.h"
#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>
#include <CUnit/TestDB.h>
#include <CUnit/TestRun.h>


void PopulateList(LinkedList *list) {
    int size = sizeof("test 1");
    LinkedListAppend(list, "test 1", size);
    LinkedListAppend(list, "test 2", size);
    LinkedListAppend(list, "test 3", size);
    LinkedListAppend(list, "test 4", size);
    LinkedListAppend(list, "test 5", size);
}

void TestAppend(void) {
    LinkedList list = LinkedListGetEmptyList();
    PopulateList(&list);
    CU_ASSERT(list.length == 5);
    CU_ASSERT(list.head != NULL);
    printf("First: %s\n", (char*)list.head->data);
    printf("Last: %s\n", (char*)list.tail->data);
    CU_ASSERT(memcmp(list.head->data, "test 2", sizeof("test 1")) == 0);
    CU_ASSERT(strcmp(list.head->next->next->next->next->data, "test 5") == 0);
    CU_ASSERT(list.head->next->next->next->next->next == NULL);
    LinkedListClear(&list);
}


void TestGetAt(void) {
    LinkedList list = LinkedListGetEmptyList();
    PopulateList(&list);
    CU_ASSERT(strcmp(LinkedListGetAt(&list, 0), "test 1") == 0);
    CU_ASSERT(strcmp(LinkedListGetAt(&list, 1), "test 2") == 0);
    CU_ASSERT(strcmp(LinkedListGetAt(&list, 4), "test 5") == 0);
    CU_ASSERT(LinkedListGetAt(&list, 5) == NULL);
    LinkedListClear(&list);
}

void TestPrepend(void) {
    LinkedList list = LinkedListGetEmptyList();
    PopulateList(&list);
    LinkedListPrepend(&list, "test 6");
    LinkedListPrepend(&list, "test 7");
    LinkedListPrepend(&list, "test 8");
    LinkedListPrepend(&list, "test 9");
    LinkedListPrepend(&list, "test 10");
    CU_ASSERT(strcmp(LinkedListGetAt(&list, 0), "test 10") == 0);
    CU_ASSERT(strcmp(LinkedListGetAt(&list, 1), "test 9") == 0);
    CU_ASSERT(strcmp(LinkedListGetAt(&list, 5), "test 1") == 0);
    CU_ASSERT(strcmp(LinkedListGetAt(&list, 9), "test 5") == 0);
    CU_ASSERT(LinkedListGetAt(&list, 10) == 0);
    CU_ASSERT(list.length == 10);
    LinkedListClear(&list);
}

void TestRemoveAt(void) {
    LinkedList list = LinkedListGetEmptyList();
    PopulateList(&list);
    CU_ASSERT(strcmp(LinkedListRemoveAt(&list, 0), "test 1") == 0);
    CU_ASSERT(list.length == 4);
    CU_ASSERT(strcmp(LinkedListRemoveAt(&list, 3), "test 5") == 0);
    CU_ASSERT(strcmp(LinkedListRemoveAt(&list, 2), "test 4") == 0);
    CU_ASSERT(strcmp(LinkedListRemoveAt(&list, 0), "test 2") == 0);
    CU_ASSERT(list.length == 1);
    CU_ASSERT(strcmp(LinkedListRemoveAt(&list, 0), "test 3") == 0);
    CU_ASSERT(list.length == 0);
    CU_ASSERT(LinkedListRemoveAt(&list, 0) == 0);
    LinkedListClear(&list);
}

void TestRemoveFirst(void) {
    LinkedList list = LinkedListGetEmptyList();
    PopulateList(&list);
    CU_ASSERT(strcmp(LinkedListRemoveFirst(&list), "test 1") == 0);
    CU_ASSERT(strcmp(LinkedListRemoveFirst(&list), "test 2") == 0);
    CU_ASSERT(list.length == 3);
    CU_ASSERT(strcmp(LinkedListRemoveFirst(&list), "test 3") == 0);
    CU_ASSERT(strcmp(LinkedListRemoveFirst(&list), "test 4") == 0);
    CU_ASSERT(list.length == 1);
    CU_ASSERT(strcmp(LinkedListRemoveFirst(&list), "test 5") == 0);
    CU_ASSERT(list.length == 0);
    CU_ASSERT(LinkedListRemoveFirst(&list) == 0);
    LinkedListClear(&list);
}

void TestLinkedListRemoveLast(void) {
    LinkedList list = LinkedListGetEmptyList();
    PopulateList(&list);
    CU_ASSERT(strcmp(LinkedListRemoveLast(&list), "test 5") == 0);
    CU_ASSERT(strcmp(LinkedListRemoveLast(&list), "test 4") == 0);
    CU_ASSERT(strcmp(LinkedListRemoveLast(&list), "test 3") == 0);
    CU_ASSERT(strcmp(LinkedListRemoveLast(&list), "test 2") == 0);
    CU_ASSERT(strcmp(LinkedListRemoveLast(&list), "test 1") == 0);
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
    // CU_add_test(suite, "GetAt", TestGetAt);
    // CU_add_test(suite, "Prepend", TestPrepend);
    // CU_add_test(suite, "LinkedListRemoveAt", TestRemoveAt);
    // CU_add_test(suite, "LinkedListRemoveFirst", TestRemoveFirst);
    // CU_add_test(suite, "LinkedListRemoveLast", TestLinkedListRemoveLast);
    // CU_add_test(suite, "Clear", TestClear);
}

