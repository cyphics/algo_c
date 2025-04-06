#include "unity.h"  // Unity test framework
#include "algorithms.h"  // Your library header
#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>
#include <CUnit/TestDB.h>
#include <CUnit/TestRun.h>

// Test setup and teardown functions (optional)
void setUp(void) { /* Setup code (if needed) */ }
void tearDown(void) { /* Cleanup code (if needed) */ }
//
// Test case: example test for your library
void test_function1_should_return_expected_result(void) {
    int result = 10;  // Call a function from your library
    TEST_ASSERT_EQUAL(10, result);  // Validate the result
}

void test_function2_should_return_expected_value(void) {
    int result = 6;  // Call another function
    TEST_ASSERT_EQUAL(6, result);
}
void test_linked_list(void);
// void TestLinkedList(CU_pSuite suite);
void TestDLList(CU_pSuite suite);
int main(void) {
    // UNITY_BEGIN();  // Initialize Unity
    // RUN_TEST(test_linked_list);
    //
    // // Run test cases
    // // RUN_TEST(test_function1_should_return_expected_result);
    // // RUN_TEST(test_function2_should_return_expected_value);
    //
    // return UNITY_END();  // Finish Unity and return summary
    CU_initialize_registry();
    CU_pSuite suite = CU_add_suite("Sorting", 0, 0);
    TestDLList(suite);
    /*CU_add_test(suite, "Queue", TestQueue);*/
    /*CU_add_test(suite, "Ring Buffer", TestRingBuffer);*/
    // CU_add_test(suite, "Quick Sort", TestQuickSort);
    // CU_add_test(suite, "Binary Tree", TestBinarytree);
    // TestStack(suite);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return 0;
}
