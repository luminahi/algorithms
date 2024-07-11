#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "selection_sort.h"

#define ARRAY_SIZE 32

int main(int argc, char* argv[]) {
    int array[ARRAY_SIZE];

    srand(time(0));
    for (int i = 0; i < ARRAY_SIZE; i++) array[i] = rand() % 100;

    selection_sort(array, ARRAY_SIZE);
    for (int i = 0; i < ARRAY_SIZE; i++) printf("[%d] ", array[i]);

    return 0;
}