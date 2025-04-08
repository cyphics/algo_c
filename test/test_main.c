#include "algorithms.h"  // Your library header
#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>
#include <CUnit/TestDB.h>
#include <CUnit/TestRun.h>

// Test setup and teardown functions (optional)
//

int test_linked_list(void);

void TestDLList(CU_pSuite suite);
int main(void) {
    test_linked_list();
}
