#include <stdio.h>
#include "merge_sort.h"
#include <time.h>
#include <stdlib.h>

#define MAX_SIZE 102400000

int main(int argc, char* argv[]) {
    int* array = (int*) malloc(sizeof(int) * MAX_SIZE);

    srand(time(0));
    for (int i = 0; i < MAX_SIZE; i++) {
	array[i] = rand();
    }

    merge_sort(array, 0, MAX_SIZE - 1);
    
    printf("[%d] ", MAX_SIZE);

    return 0;
}
