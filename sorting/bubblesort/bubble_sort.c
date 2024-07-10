#include "bubble_sort.h"

void swap(int* a, int* b) {
    int aux = *a;
    *a = *b;
    *b = aux;   
}

void bubble_sort(int* array, int array_size) {
    for (int i = 0; i < array_size - 1; i++) {
        for (int j = i + 1; j < array_size; j++) {
            if (array[i] > array[j]) 
                swap(&array[i], &array[j]);
        }
    }
}
