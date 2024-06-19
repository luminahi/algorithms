#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char getDecimalLength(long value) {
    if (value == 0) return 0;
    const long absoluteValue = value < 0 ? value * -1 : value;
    return log10(absoluteValue);
}

char getBinaryLength(long value) {
    if (value == 0) return 0;
    const long absoluteValue = value < 0 ? value * -1 : value;
    return log2(absoluteValue);
}

int main(int argc, char ** argv) {
    long arg1 = 99920202010L;
    long arg2 = -0b11111111111111111111111111111111L;

    const char result1 = getDecimalLength(arg1);
    const char result2 = getBinaryLength(arg2);

    printf("length of arg1: %d\n", result1 + 1);
    printf("length of arg2: %d\n", result2 + 1);

    return 0;
}
