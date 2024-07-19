#ifndef _HEAP_SORT_H
#define _HEAP_SORT_H

#define MAX_SIZE 16

typedef struct {
    int data[MAX_SIZE];
    int size;
} MinHeap;

void insert(MinHeap*, int);
void swap(int*, int*);
void heapifyUp(MinHeap*, int);
void heapifyDown(MinHeap*, int);
void printHeap(MinHeap*);
void printArray(int*);
int extractMin(MinHeap*);
int* sort(MinHeap*);

#endif