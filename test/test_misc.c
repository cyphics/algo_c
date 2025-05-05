#include "ringBuffer.h"
#include "unity.h"  // Unity test framework
#include "queue.h"
#include "unity_internals.h"
#include <stdlib.h>

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


void test_ring_buffer(void) {
    RingBuffer buffer = GetRingBuffer(5);

    AddToStart(&buffer, 1);
    TEST_ASSERT_EQUAL(PeekStart(&buffer), 1);
    TEST_ASSERT_EQUAL(PeekEnd(&buffer), 1);
    TEST_ASSERT_EQUAL(buffer.length, 1);

    AddToEnd(&buffer, 2);
    TEST_ASSERT_EQUAL(PeekStart(&buffer), 1);
    TEST_ASSERT_EQUAL(PeekEnd(&buffer), 2);
    TEST_ASSERT_EQUAL(buffer.length, 2);

    AddToStart(&buffer, 3);
    TEST_ASSERT_EQUAL(RemoveFromStart(&buffer), 3);
    TEST_ASSERT_EQUAL(RemoveFromEnd(&buffer), 2);
    TEST_ASSERT_EQUAL(PeekStart(&buffer), 1);
    TEST_ASSERT_EQUAL(PeekEnd(&buffer), 1);
    TEST_ASSERT_EQUAL(buffer.length, 1);

    PrintRingBuffer(&buffer);
    AddToStart(&buffer, 4);
    AddToStart(&buffer, 5);
    AddToStart(&buffer, 6);
    TEST_ASSERT_EQUAL(buffer.length, 4);

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


int test_misc(void) {
    UNITY_BEGIN();  // Initialize Unity
    RUN_TEST(test_ring_buffer);
    RUN_TEST(test_queue);
    return UNITY_END();
}
