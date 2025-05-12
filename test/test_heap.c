#include "binary_tree.h"
#include "unity.h"
#include "unity_internals.h"
#include "heap.h"

void test_merge_nodes(void) {

    BinaryNode *cmp;
    BinaryNode *n1 = GetNode(3, NULL, NULL);
    BinaryNode *n2 = GetNode(5, NULL, NULL);
    BinaryNode *node = MergeNodes(n1, n2);
    cmp = GetNode(3, GetNode(5, NULL, NULL), NULL);
    TEST_ASSERT_EQUAL(CompareTrees(node, cmp), true);
}

void test_min_heap(void){
    Heap heap = GetHeap();
    BinaryNode *cmp;

    TEST_ASSERT_EQUAL(heap.length, 0);

    MinHeapInsert(&heap, 5);
    MinHeapInsert(&heap, 3);
    cmp = GetNode(3, GetNode(5, NULL, NULL), NULL);
    TEST_ASSERT_EQUAL(CompareTrees(heap.head, cmp), true);

    MinHeapInsert(&heap, 69);
    cmp->right = GetNode(69, NULL, NULL);
    TEST_ASSERT_EQUAL(CompareTrees(heap.head, cmp), true);


    MinHeapInsert(&heap, 420);
    cmp->left->left = GetNode(420, NULL, NULL);
    TEST_ASSERT_EQUAL(CompareTrees(heap.head, cmp), true);

    MinHeapInsert(&heap, 4);
    cmp->right = GetNode(4, cmp->right, NULL);
    TEST_ASSERT_EQUAL(CompareTrees(heap.head, cmp), true);

    MinHeapInsert(&heap, 1);
    cmp = GetNode(1, cmp, cmp->right);
    cmp->left->right = NULL;
    
    TEST_ASSERT_EQUAL(CompareTrees(heap.head, cmp), true);
    MinHeapInsert(&heap, 8);
    MinHeapInsert(&heap, 7);


    TEST_ASSERT_EQUAL(8, heap.length);
    TEST_ASSERT_EQUAL(1, MinHeapDelete(&heap));
    TEST_ASSERT_EQUAL(3, MinHeapDelete(&heap));
    TEST_ASSERT_EQUAL(4, MinHeapDelete(&heap));
    TEST_ASSERT_EQUAL(5, MinHeapDelete(&heap));
    TEST_ASSERT_EQUAL(4, heap.length);
    TEST_ASSERT_EQUAL(7, MinHeapDelete(&heap));
    TEST_ASSERT_EQUAL(8, MinHeapDelete(&heap));
    TEST_ASSERT_EQUAL(69, MinHeapDelete(&heap));
    TEST_ASSERT_EQUAL(420, MinHeapDelete(&heap));
    TEST_ASSERT_EQUAL(0, heap.length);
}


int test_heap(void) {
    UNITY_BEGIN();  // Initialize Unity
    RUN_TEST(test_min_heap);
    return UNITY_END();
}
