#include "unity.h"  // Unity test framework
#include "binary_tree.h"
#include "trees.h"
#include "unity_internals.h"
#include "ringBuffer.h"

void test_preorder_search(void) {
    BinaryNode *tree = InitBinaryTree();
    RingBuffer buffer = GetRingBuffer(10);
    //int expected[] = {20, 10, 5,  7,  15, 50, 30, 29, 45, 100};
    int expected[] = {20, 50, 30,  45,  29, 100, 10, 15, 5, 7};

    WalkTreePreorder(tree, &buffer);
    int *result = RingBufferToArray(&buffer);
    TEST_ASSERT_EQUAL_INT32_ARRAY(expected, result, 10);
}

int test_binary_tree(void) {
    UNITY_BEGIN();  // Initialize Unity
    RUN_TEST(test_preorder_search);
    return UNITY_END();
}
