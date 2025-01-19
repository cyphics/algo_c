#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>
#include <CUnit/TestDB.h>
#include <CUnit/TestRun.h>
#include <stdbool.h>
#include <stdint.h>
#include "algo_lib.h"
/*#include "linked_list_int.h"*/
#include "linked_list_str.h"
#include "helpers.h"



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

int main(void) {
    CU_initialize_registry();
    CU_pSuite suite = CU_add_suite("Sorting", 0, 0);
    TestLinkedList(suite);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return 0;
}
