#include <stdbool.h>
#include <stdio.h>

int partition(int *array, int lo, int hi) {
    int pivot = array[hi];
    int current;

    for (current = lo; current  < hi; current ++) {
        // if bigger than pivot
        if (array[current] > pivot) {
            bool foundSmaller = false;
            // find smaller than pivot and swap
            for (int j = current + 1; j < hi - 1; j++) {
                if (array[j] < pivot) {
                    int tmp = array[j];
                    array[j] = array[current];
                    array[current] = tmp;
                    foundSmaller = true;
                    break;
                }
            }

            if (!foundSmaller) {
                // if not smaller found, exit
                array[hi] = array[current];
                array[current] = pivot;
                return current;
            }
        }
    }
    return hi;
}


void qs(int *array, int lo, int hi) {
    if (lo >= hi) {
        return;
    }
    int idx = partition(array, lo, hi);
    qs(array, lo, idx - 1);
    qs(array, idx + 1, hi);
}

void QuickSort(int *array, int length) {
    qs(array, 0, length - 1);
}
