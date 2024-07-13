#include "insertion_sort.h"

void swap(int* a, int* b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

void insertion_sort(int* array, int array_size) {
    int i = 0;
    while (i < array_size) {
        int j = i;

        while (j > 0 && array[j - 1] > array[j]) {
            swap(&array[j - 1], &array[j]);
            j--;
        }

        i++;
    }
}
