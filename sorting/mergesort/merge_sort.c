#include <stdlib.h>
#include "merge_sort.h"

void merge(int* array, int start, int mid, int end) {
    int size = end - start + 1;
    int index_start = start;
    int index_mid = mid + 1;
    int index_aux = 0;

    int* array_aux = (int*) malloc(sizeof(int) * size);

    while (index_start <= mid && index_mid <= end) {
        if (array[index_start] < array[index_mid]) {
            array_aux[index_aux] = array[index_start];
            index_start++;
        } else {
            array_aux[index_aux] = array[index_mid];
            index_mid++;
        }

        index_aux++;
    }

    while (index_start <= mid) {
        array_aux[index_aux] = array[index_start];
        index_aux++;
        index_start++;
    }

    while (index_mid <= end) {
        array_aux[index_aux] = array[index_mid];
        index_aux++;
        index_mid++;
    }

    for (index_aux = start; index_aux <= end; index_aux++) {
        array[index_aux] = array_aux[index_aux - start];
    }

    free(array_aux);
}

void merge_sort(int* array, int start, int end) {
    if (start < end) {
        int mid = (end + start) / 2;

        merge_sort(array, start, mid);
        merge_sort(array, mid + 1, end);

        merge(array, start, mid, end);
    }
}
