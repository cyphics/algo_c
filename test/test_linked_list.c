#include "linked_list.h"
#include "unity.h"  // Unity test framework
#include <stdlib.h>
#include "unity_internals.h"

void setUp(void) { /* Setup code (if needed) */ }
void tearDown(void) { /* Cleanup code (if needed) */ }

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
    TEST_ASSERT_EQUAL(5, list.length);
    TEST_ASSERT_NOT_NULL(list.head);
    TEST_ASSERT_EQUAL_STRING("test 1", list.head->data);
    TEST_ASSERT_EQUAL_STRING("test 5", list.head->next->next->next->next->data);
    TEST_ASSERT_NULL(list.head->next->next->next->next->next);    
    dllist_clear(&list);
}

void test_clear_list(void) {
    DLList l = get_empty_dllist();
    _populate_list(&l);
    dllist_clear(&l);
    TEST_ASSERT_NULL(l.head);
    TEST_ASSERT_NULL(l.tail);
    TEST_ASSERT_EQUAL(0, l.length);
}

void test_get_at(void) {
    DLList list = get_empty_dllist();
    _populate_list(&list);
    TEST_ASSERT_EQUAL_STRING("test 1", dllist_get_at(&list, 0));
    TEST_ASSERT_EQUAL_STRING("test 2", dllist_get_at(&list, 1));
    TEST_ASSERT_EQUAL_STRING("test 5", dllist_get_at(&list, 4));
    TEST_ASSERT_NULL(dllist_get_at(&list, 5));
    dllist_clear(&list);
}

void test_prepend(void) {
    DLList list = get_empty_dllist();
    _populate_list(&list);
    int size = sizeof("test 1");
    dllist_prepend(&list, "test 6", size);
    dllist_prepend(&list, "test 7", size);
    dllist_prepend(&list, "test 8", size);
    dllist_prepend(&list, "test 9", size);
    dllist_prepend(&list, "test 10", size + 1);
    TEST_ASSERT_EQUAL_STRING("test 10", dllist_get_at(&list, 0));
    TEST_ASSERT_EQUAL_STRING("test 9",  dllist_get_at(&list, 1));
    TEST_ASSERT_EQUAL_STRING("test 1",  dllist_get_at(&list, 5));
    TEST_ASSERT_EQUAL_STRING("test 5",  dllist_get_at(&list, 9));
    TEST_ASSERT_NULL(dllist_get_at(&list, 10));
    TEST_ASSERT_EQUAL(10, list.length);
    dllist_clear(&list);
}

void test_pop_first(void) {
    DLList list = get_empty_dllist();
    _populate_list(&list);
    for (int i = 0; i < 5; i++) {
        void* result = dllist_pop_first(&list);
        char expected[7];
        snprintf(expected, sizeof("test 1"), "test %i", i+1);
        TEST_ASSERT_EQUAL_STRING(expected, result);
        free(result);
    }
    TEST_ASSERT_NULL(dllist_pop_first(&list));
}

void test_pop_last(void) {
    DLList list = get_empty_dllist();
    _populate_list(&list);
    for (int i = 0; i < 5; i++) {
        void* result = dllist_pop_last(&list);
        char expected[7];
        snprintf(expected, sizeof("test 1"), "test %i", 5-i);
        TEST_ASSERT_EQUAL_STRING(expected, result);
        free(result);
    }
    dllist_clear(&list);
}

void test_pop_at(void) {
    DLList list = get_empty_dllist();
    _populate_list(&list);
    TEST_ASSERT_EQUAL_STRING("test 4", dllist_pop_at(&list, 3));
    // TEST_ASSERT_EQUAL_STRING("test 1", dllist_pop_at(&list, 0));
    // TEST_ASSERT_EQUAL_STRING("test 3", dllist_pop_at(&list, 3));
    // TEST_ASSERT_EQUAL_STRING("test 5", dllist_pop_at(&list, 1));
    // TEST_ASSERT_EQUAL_STRING("test 2", dllist_pop_at(&list, 0));
    // TEST_ASSERT_EQUAL_STRING("test 1", dllist_pop_at(&list, 0));
    // test_equal_str(DLListRemoveAt(&list, 0), "test 2");
    // test_equal_str(DLListRemoveAt(&list, 0), "test 3");
    // test_equal_str(DLListRemoveAt(&list, 0), "test 4");
    // test_equal_str(DLListRemoveAt(&list, 0), "test 5");
    // CU_ASSERT(list.length;
    // test_equal_str(DLListRemoveAt(&list, 3), "test 5");
    // test_equal_str(DLListRemoveAt(&list, 2), "test 4");
    // test_equal_str(DLListRemoveAt(&list, 0), "test 2");
    // CU_ASSERT(list.length == 1);
    // test_equal_str(DLListRemoveAt(&list, 0), "test 3");
    // CU_ASSERT(list.length;
    // CU_ASSERT(DLListRemoveAt(&list, 0);
}

// void TestClear(void) {
//     DLList list = get_empty_dllist();
//     _populate_list(&list);
//     dllist_clear(&list);
//     CU_ASSERT(list.length == 0);
//     CU_ASSERT(list.head == NULL);
//     CU_ASSERT(list.tail == NULL);
// }
//
// void TestDLList(CU_pSuite suite) {
    // CU_add_test(suite, "Append", test_append);
    // CU_add_test(suite, "Clear", TestClearList);
    // CU_add_test(suite, "GetAt", TestGetAt);
    // CU_add_test(suite, "Prepend", TestPrepend);
    // CU_add_test(suite, "DLListPopFirst", TestPopFirst);
    // CU_add_test(suite, "DLListPopLast", TestLinkedListPopLast);
    // CU_add_test(suite, "DLListPopAt", TestPopAt);
    // CU_add_test(suite, "Clear", TestClear);
// }

int test_linked_list(void){
    UNITY_BEGIN();  // Initialize Unity
    RUN_TEST(test_append);
    RUN_TEST(test_clear_list);
    RUN_TEST(test_get_at);
    RUN_TEST(test_prepend);
    RUN_TEST(test_pop_first);
    RUN_TEST(test_pop_last);
    RUN_TEST(test_pop_at);
    return UNITY_END();  // Finish Unity and return summary
}
