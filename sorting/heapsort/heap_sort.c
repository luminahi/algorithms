#include <stdio.h>
#include "heap_sort.h"

void insert(MinHeap* heap, int value) {
    if (heap->size >= MAX_SIZE) {
        printf("Heap is full\n");
        return;
    }

    heap->size++;
    heap->data[heap->size - 1] = value;
    heapifyUp(heap, heap->size - 1);
}

void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void heapifyUp(MinHeap* heap, int index) {
    int parent = (index - 1) / 2;
    if (parent >= 0 && heap->data[index] < heap->data[parent]) {
        swap(&heap->data[index], &heap->data[parent]);
        heapifyUp(heap, parent);
    }
}

void heapifyDown(MinHeap* heap, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < heap->size && heap->data[left] < heap->data[smallest])
        smallest = left;

    if (right < heap->size && heap->data[right] < heap->data[smallest])
        smallest = right;
    
    if (smallest != index) {
        swap(&heap->data[smallest], &heap->data[index]);
        heapifyDown(heap, smallest);
    }
}

void printHeap(MinHeap* heap) {
    printf("Size: %d\n", heap->size);
    
    for (int i = 0; i < heap->size; i++) {
        printf("[%d] ", heap->data[i]);
    }
    printf("\n\n");
}

void printArray(int* array) {
    for (int i = 0; i < MAX_SIZE; i++) {
        printf("[%d] ", array[i]);
    }
}

int extractMin(MinHeap* heap) {
    if (heap->size <= 0) {
        printf("Heap is empty\n");
        return -1;
    }

    int value = heap->data[0];
    heap->data[0] = heap->data[heap->size - 1];
    heap->data[heap->size - 1] = 0;
    heap->size--;
    heapifyDown(heap, 0);
    return value;
}

int* sort(MinHeap* heap) {
    int size = heap->size - 1;

    for (int i = 0; i < MAX_SIZE; i++) {
        heap->data[size] = extractMin(heap);
        size--;
    }
}