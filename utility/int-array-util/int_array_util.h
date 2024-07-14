#ifndef _INT_ARRAY_UTIL
#define _INT_ARRAY_UTIL

typedef struct FilterResult {
    int* array;
    int size;
} FilterResult;

void for_each(int*, int, void (*)(int));

int* map(int*, int, int (*)(int));

FilterResult filter(int*, int, int (*)(int));

#endif