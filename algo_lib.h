#include <stdbool.h>

struct library {
	bool (*BinarySearch)(int target, int* sorted_array, int array_length);
	int (*IndexOf)(void* target, void* array, int array_length, int size);
};

extern const struct library Sorting;
