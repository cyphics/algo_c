#include "unity.h"  // Unity test framework
#include "queue.h"
#include "unity_internals.h"

void test_queue(void) {
    
    Queue list = GetQueue();

    EnQueue(&list, 5);
    EnQueue(&list, 7);
    EnQueue(&list, 9);

    TEST_ASSERT_EQUAL(5, DeQueue(&list));
    TEST_ASSERT_EQUAL(2, list.length);

    EnQueue(&list, 11);
    TEST_ASSERT_EQUAL(7,  DeQueue(&list));
    TEST_ASSERT_EQUAL(9,  DeQueue(&list));
    TEST_ASSERT_EQUAL(11, PeekQueue(&list));
    TEST_ASSERT_EQUAL(11, DeQueue(&list));
    TEST_ASSERT_EQUAL(0,  DeQueue(&list));
    TEST_ASSERT_EQUAL(0,  list.length);

    EnQueue(&list, 69);
    TEST_ASSERT_EQUAL(69, PeekQueue(&list));
    TEST_ASSERT_EQUAL(1,  list.length);
}


int test_misc(void) {
    UNITY_BEGIN();  // Initialize Unity
    RUN_TEST(test_queue);
    return UNITY_END();
}
