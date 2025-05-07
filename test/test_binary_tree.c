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
    
    TEST_ASSERT_EQUAL(BreadthFirstSearch(tree, 0), false);
    TEST_ASSERT_EQUAL(BreadthFirstSearch(tree, 20), true);
    TEST_ASSERT_EQUAL(BreadthFirstSearch(tree, 100), true);
    TEST_ASSERT_EQUAL(BreadthFirstSearch(tree, 31), false);
    TEST_ASSERT_EQUAL(BreadthFirstSearch(tree, 7), true);
}

void test_compare_trees(void) {
    BinaryNode *t1 = GetNode(30, 
                        GetNode(45, NULL, NULL), 
                        GetNode(29, NULL, NULL));
    BinaryNode *t2 = GetNode(30, 
                        GetNode(45, 
                            GetNode(29, NULL, NULL), 
                            NULL),
                        NULL);
    BinaryNode *t3 = GetNode(30, 
                        GetNode(45, NULL, NULL), 
                        GetNode(29, GetNode(1, NULL, NULL), NULL));

   TEST_ASSERT_EQUAL(CompareTrees(t1, t1), true);
   TEST_ASSERT_EQUAL(CompareTrees(t1, t2), false);
   TEST_ASSERT_EQUAL(CompareTrees(t1, t3), false);

}

int test_binary_tree(void) {
    UNITY_BEGIN();  // Initialize Unity
    RUN_TEST(test_binary_walk);
    RUN_TEST(test_binary_seach);
    RUN_TEST(test_compare_trees);
    return UNITY_END();
}
