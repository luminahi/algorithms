#include <stdlib.h>
#include "int_array_util.h"

void for_each(int* array, int array_size, void (*fn)(int)) {
    for (int i = 0; i < array_size; i++) {
        fn(array[i]);
    }
}

int* map(int* array, int array_size, int (*fn)(int)) {
    int* mapped_array = (int*) malloc(sizeof(int) * array_size);
    int i = 0;

    while (i < array_size) {
        mapped_array[i] = fn(array[i]);
        i++;
    }

    return mapped_array;
}

FilterResult filter(int* array, int array_size, int (*fn)(int)) {
    int temp_array[array_size];
    int i = 0;
    int j = 0;

    while (i < array_size) {
        if (fn(array[i])) {
            temp_array[j] = array[i];
            j++;
        }
        
        i++;
    }

    int* filtered_array = (int*) malloc(sizeof(int) * j);
    for (int i = 0; i < j; i++) filtered_array[i] = temp_array[i];

    FilterResult result = { .array = filtered_array, .size = j };

    return result;
}