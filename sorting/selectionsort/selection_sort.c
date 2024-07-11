#include "selection_sort.h"

void swap(int* a, int* b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

void selection_sort(int* array, int array_size) {
    for (int i = 0; i < array_size; i++) {
        int min_index = i;
        for (int j = i + 1; j < array_size; j++) {
            if (array[min_index] > array[j]) {
                min_index = j;
            }
        }

        swap(&array[min_index], &array[i]);
    }
}
