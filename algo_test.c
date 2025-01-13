#include <stdio.h>
#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>
#include <stdbool.h>
#include "algo_lib.h"

void test_sorting() {
	int array[] = {1, 2, 4, 5, 7};
	CU_ASSERT(Sorting.BinarySearch(5, array, 5));
}

int main() {
	printf("Init tests\n");
	CU_initialize_registry();
	CU_pSuite suite = CU_add_suite("Sorting", 0, 0);
	CU_add_test(suite, "Sorting", test_sorting);
	CU_basic_run_tests();
	CU_cleanup_registry();
}
