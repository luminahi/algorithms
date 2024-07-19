#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "heap_sort.h"

#define MAX_SIZE 16

int main(int argc, char * argv[]) {
    MinHeap heap;
    heap.size = 0;

    // init the heap with all slots with 0
    for (int i = 0; i < MAX_SIZE; i++) heap.data[i] = 0;

    // insert random values to heap
    srand(time(0));
    for (int i = MAX_SIZE - 1; i >= 0; i--) {
        insert(&heap, rand() % 255);
    }

    printHeap(&heap);

    sort(&heap);

    printArray(heap.data);

    return 0;
}
