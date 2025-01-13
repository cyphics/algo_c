#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "algo_lib.h"
#include "helpers.h"

bool BinarySearch(int target, int *sorted_list, int list_size) {
	return false;
}

int IndexOf(void* target, void* array, int array_length, int size) {
	for(int idx = 0; idx < array_length; idx++) {
		void *position = array + idx * size;
		/*printf("LHS: ");*/
		/*PrintBytes(target, size);*/
		/*printf("RHS: ");*/
		/*PrintBytes(position, size);*/
		int result = memcmp(target, position, size);
		if (!result) {
			return idx;
		}
	}
	return -1;
}

const struct library Sorting = {
	.BinarySearch = BinarySearch,
	.IndexOf = IndexOf
};
