#include <stdio.h>
#include "algo.h"

void BinarySearch(void) {
	printf("Running binary search\n");
}

const struct library Sorting = {
	.BinarySearch = BinarySearch
};
