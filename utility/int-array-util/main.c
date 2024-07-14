#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include "int_array_util.h"

void print(int element) {
    printf("[%d] ", element);
}

int add_ten(int number) {
    return number + 10;
}

int greater_than_zero(int number) {
    return number > 0 ? 1 : 0;
}

int divisible_by_two(int number) {
    return number % 2 == 0 ? 1 : 0;
}

int main(int argc, char* argv[]) {
    int* array_result = NULL;
    int array[] = {56, 32, 23, 17, 11, 81, 13, 10}; 
    int length = sizeof(array) / sizeof(int);

    printf("base array -> ");
    for_each(array, length, &print);
    printf("\n");
    
    array_result = map(array, length, &add_ten);

    printf("mapped array (add ten) -> ");
    for_each(array_result, length, &print);
    free(array_result);
    printf("\n");

    FilterResult result = filter(array, length, &divisible_by_two);

    printf("filtered array (divisible by two) -> ");
    for_each(result.array, result.size, &print);
    free(result.array);
    printf("\n");

    return 0;
}