#include "linked_list.h"
#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>
#include <CUnit/TestDB.h>
#include <CUnit/TestRun.h>
#include <stdlib.h>
#include "unittest_helpers.h"


void _populate_list(DLList *list) {
    int size = sizeof("test 1");
    dllist_append(list, "test 1", size);
    dllist_append(list, "test 2", size);
    dllist_append(list, "test 3", size);
    dllist_append(list, "test 4", size);
    dllist_append(list, "test 5", size);
}

void DebugPrintList(DLList *l) {
    struct Node *current = l->head;
    int counter = 0;
    while (current != NULL && counter < 10) {
        printf("Node %i: %s\n", counter, (char*)current->data);
        current = current->next;
        counter++;
    }
}

void test_append(void) {
    DLList list = get_empty_dllist();
    _populate_list(&list);
     // TEST_ASSERT_EQUAL(5, list.length);
     // TEST_ASSERT_EQUAL(5, list.length);
     // TEST_ASSERT_EQUAL(1, list.length);
    CU_ASSERT(list.length == 5);
    // CU_ASSERT(list.head != NULL);
    // test_equal_data(list.head->data, "test 1", sizeof("test 1"));
    // test_equal_str(list.head->data, "test 1");
    // test_equal_str(list.head->data, "test 1");
    // test_equal_str(list.head->next->next->next->next->data, "test 5");
    // CU_ASSERT(list.head->next->next->next->next->next == NULL);
    // dllist_clear(&list);
}

// void TestClearList(void) {
//     DLList l = get_empty_dllist();
//     _populate_list(&l);
//     dllist_clear(&l);
// }
//
// void TestGetAt(void) {
//     DLList list = get_empty_dllist();
//     _populate_list(&list);
//     test_equal_str(dllist_get_at(&list, 0), "test 1");
//     test_equal_str(dllist_get_at(&list, 1), "test 2");
//     test_equal_str(dllist_get_at(&list, 4), "test 5");
//     CU_ASSERT(dllist_get_at(&list, 5) == NULL);
//     dllist_clear(&list);
// }
//
// void TestPrepend(void) {
//     DLList list = get_empty_dllist();
//     _populate_list(&list);
//     int size = sizeof("test 1");
//     dllist_prepend(&list, "test 6", size);
//     dllist_prepend(&list, "test 7", size);
//     dllist_prepend(&list, "test 8", size);
//     dllist_prepend(&list, "test 9", size);
//     dllist_prepend(&list, "test 10", size + 1);
//     test_equal_str(dllist_get_at(&list, 0), "test 10");
//     test_equal_str(dllist_get_at(&list, 1), "test 9");
//     test_equal_str(dllist_get_at(&list, 5), "test 1");
//     test_equal_str(dllist_get_at(&list, 9), "test 5");
//     CU_ASSERT(dllist_get_at(&list, 10) == 0);
//     CU_ASSERT(list.length == 10);
//     dllist_clear(&list);
// }
//
// void TestPopFirst(void) {
//     DLList list = get_empty_dllist();
//     _populate_list(&list);
//     for (int i = 0; i < 5; i++) {
//         void* result = dll_pop_first(&list);
//         char expected[7];
//         snprintf(expected, sizeof("test 1"), "test %i", i+1);
//         test_equal_str(result, expected);
//         free(result);
//     }
//     CU_ASSERT(dll_pop_first(&list) == NULL);
// }
//
// void TestDLListPopLast(void) {
//     DLList list = get_empty_dllist();
//     _populate_list(&list);
//     for (int i = 0; i < 5; i++) {
//         void* result = dllist_pop_last(&list);
//         printf("res: %s", result);
//         char expected[7];
//         snprintf(expected, sizeof("test 1"), "test %i", 5-i);
//         test_equal_str(result, expected);
//         free(result);
//     }
//     dllist_clear(&list);
// }
//
// void TestPopAt(void) {
//     DLList list = get_empty_dllist();
//     _populate_list(&list);
//     test_equal_str(dllist_pop_at(&list, 3), "test 4");
//     test_equal_str(dllist_pop_at(&list, 0), "test 1");
//     test_equal_str(dllist_pop_at(&list, 3), "test 3");
//     test_equal_str(dllist_pop_at(&list, 1), "test 5");
//     test_equal_str(dllist_pop_at(&list, 0), "test 2");
//     test_equal_str(dllist_pop_at(&list, 0), "test 1");
//     // test_equal_str(DLListRemoveAt(&list, 0), "test 2");
//     // test_equal_str(DLListRemoveAt(&list, 0), "test 3");
//     // test_equal_str(DLListRemoveAt(&list, 0), "test 4");
//     // test_equal_str(DLListRemoveAt(&list, 0), "test 5");
//     // CU_ASSERT(list.length;
//     // test_equal_str(DLListRemoveAt(&list, 3), "test 5");
//     // test_equal_str(DLListRemoveAt(&list, 2), "test 4");
//     // test_equal_str(DLListRemoveAt(&list, 0), "test 2");
//     // CU_ASSERT(list.length == 1);
//     // test_equal_str(DLListRemoveAt(&list, 0), "test 3");
//     // CU_ASSERT(list.length;
//     // CU_ASSERT(DLListRemoveAt(&list, 0);
// }
//
// void TestClear(void) {
//     DLList list = get_empty_dllist();
//     _populate_list(&list);
//     dllist_clear(&list);
//     CU_ASSERT(list.length == 0);
//     CU_ASSERT(list.head == NULL);
//     CU_ASSERT(list.tail == NULL);
// }
//
void TestDLList(CU_pSuite suite) {
    CU_add_test(suite, "Append", test_append);
    // CU_add_test(suite, "Clear", TestClearList);
    // CU_add_test(suite, "GetAt", TestGetAt);
    // CU_add_test(suite, "Prepend", TestPrepend);
    // CU_add_test(suite, "DLListPopFirst", TestPopFirst);
    // CU_add_test(suite, "DLListPopLast", TestLinkedListPopLast);
    // CU_add_test(suite, "DLListPopAt", TestPopAt);
    // CU_add_test(suite, "Clear", TestClear);
}

void test_linked_list(void){
    test_append();
}
