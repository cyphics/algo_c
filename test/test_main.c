#include "algorithms.h"  // Your library header
#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>
#include <CUnit/TestDB.h>
#include <CUnit/TestRun.h>

// Test setup and teardown functions (optional)
//

int test_linked_list(void);
int test_misc(void);
int test_binary_tree(void);

int main(void) {
    // printf("test length: %l\n", "test");
    test_linked_list();
    test_misc();
    test_binary_tree();
    test_heap();
}
