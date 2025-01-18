#include "algo_lib.h"
#include "helpers.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*bool BinarySearch(int target, int *sorted_list, int list_size) { return false; }*/


int IndexOf(void *target, void *array, int array_length, int size) {
    for (int idx = 0; idx < array_length; idx++) {
        char *position = (char *)array + idx * size;
        int result = memcmp(target, position, size);
        if (!result) {
            return idx;
        }
    }
    return -1;
}

int IndexOfSorted(int array[], int target, int length) {
    int low = 0;
    int high = length;
    while (low < high) {
        int m = low + (high - low) / 2;
        if (array[m] == target) {
            return m;
        } else if (target < array[m]) {
            high = m;
        } else {
            low = m + 1;
        }
    }
    return -1;
}

void BubbleSort(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}
