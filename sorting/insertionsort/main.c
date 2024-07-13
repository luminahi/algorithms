#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "insertion_sort.h"

#define ARRAY_SIZE 16

int main(int argc, char* argv[]) {
    int array[ARRAY_SIZE];

    srand(time(NULL));
    for (int i = 0; i < ARRAY_SIZE; i++) 
        array[i] = rand() % 255;

    insertion_sort(array, ARRAY_SIZE);

    for (int i = 0; i < ARRAY_SIZE; i++)
        printf("[%d] ", array[i]);
    printf("\n");

    return 0;
}