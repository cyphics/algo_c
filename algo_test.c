#include <stdint.h>
#include <stdio.h>
#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>
#include <stdbool.h>
#include "algo_lib.h"

void test_sorting() {
	int array[] = {1, 2, 4, 5, 7};
	CU_ASSERT(Sorting.BinarySearch(5, array, 5));
}

void test_IndexOf() {
	char target1 = 'c';
	char target2 = 'z';
	char array[] = {'a', 'b', 'c', 'd', 'e'};
	int index1 = Sorting.IndexOf(&target1, &array, sizeof(array), sizeof(target1));
	int index2 = Sorting.IndexOf(&target2, &array, sizeof(array), sizeof(target2));
	CU_ASSERT(index1 == 2);
	CU_ASSERT(index2 == -1);

	double double1 = 0.1;
	double double2 = 0.2;
	double array2[] = {0.2, 3.98, 38924.9, 0.0};

	index1 = Sorting.IndexOf(&double1, &array2, sizeof(array2), sizeof(double1));
	index2 = Sorting.IndexOf(&double2, &array2, sizeof(array2), sizeof(double2));
	CU_ASSERT(index1 == -1);
	CU_ASSERT(index2 == 0);
}

int main() {
	CU_initialize_registry();
	CU_pSuite suite = CU_add_suite("Sorting", 0, 0);
	CU_add_test(suite, "IndexOf", test_IndexOf);
	/*CU_add_test(suite, "Sorting", test_sorting);*/
	CU_basic_run_tests();
	CU_cleanup_registry();
}
