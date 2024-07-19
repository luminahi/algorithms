#include <stdio.h>
#include "merge_sort.h"

int main(int argc, char* argv[]) {
    int array[] = {20, 18, 16, 10, -5};
    int length = sizeof(array)/sizeof(int);

    merge_sort(array, 0, length - 1);

    for (int i = 0; i < length; i++) {
        printf("[%d] ", array[i]);
    }

    return 0;
}