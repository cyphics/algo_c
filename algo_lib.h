#include <stdbool.h>

struct library {
	bool (*BinarySearch)(int target, int* sorted_array, int array_length);
};

extern const struct library Sorting;
