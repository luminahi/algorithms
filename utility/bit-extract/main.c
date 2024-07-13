#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

uint64_t extract_bits(uint64_t value, int n) {
    uint64_t mask = (1 << n) - 1;
    return value & mask;
}

int main(int argc, char* argv[]) {

    int result = extract_bits(0b110011, 4);
    
    printf("%d\n", result);
    return 0;
}