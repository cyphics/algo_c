#include "queue.h"
#include "unity.h"  // Unity test framework
#include <stdbool.h>
#include "binary_tree.h"
#include "trees.h"
#include "unity_internals.h"
#include "ringBuffer.h"

void test_binary_walk(void) {
    BinaryNode *tree = InitBinaryTree();
    RingBuffer buffer = GetRingBuffer(10);
    int expected[] = {20, 10, 5,  7,  15, 50, 30, 29, 45, 100};

    WalkTreePreorder(tree, &buffer);
    int *result = RingBufferToArray(&buffer);
    TEST_ASSERT_EQUAL_INT32_ARRAY(expected, result, 10);
}

void test_binary_seach(void) {
    BinaryNode *tree = InitBinaryTree();
    
    Queue queue = GetQueue();
    TEST_ASSERT_EQUAL(BreadthFirstSearch(tree, 0, &queue), false);
    ClearQueue(&queue);
    TEST_ASSERT_EQUAL(BreadthFirstSearch(tree, 20, &queue), true);
    ClearQueue(&queue);
    TEST_ASSERT_EQUAL(BreadthFirstSearch(tree, 100, &queue), true);
    ClearQueue(&queue);
    TEST_ASSERT_EQUAL(BreadthFirstSearch(tree, 31, &queue), false);
    ClearQueue(&queue);
    

}

int test_binary_tree(void) {
    UNITY_BEGIN();  // Initialize Unity
    RUN_TEST(test_binary_walk);
    RUN_TEST(test_binary_seach);
    return UNITY_END();
}
