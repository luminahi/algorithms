#include <stdio.h>

int get_length(const char* text) {
    int count = 0;
    while (*(text + count)) count++;

    return count;
}

long atoi(const char* text) {
    const int length = get_length(text);
    long multiplier = 1;
    long number = 0;

    for (int i = length - 1; i >= 0; i--) {
        int temp = (text[i] - 48);
        if (temp < 0 || temp > 9) continue;
        number += multiplier * temp;
        multiplier *= 10;
    }

    return text[0] == '-' ? number * - 1 : number;
}

int main(int argc, char* argv[]) {

    const char* n1 = "5000";
    const char* n2 = "-400020";
    const char* n3 = "50000000200020";

    printf("%ld\n", atoi(n1));
    printf("%ld\n", atoi(n2));
    printf("%ld\n", atoi(n3));
    return 0;
}