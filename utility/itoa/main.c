#include <stdio.h>
#include <stdlib.h>

char digitToChar(short d) {
    return d + 48;
}

/**
 * convert integer to string
 */
char* itoa(int number) {
    int helper = number;
    int stringSize = 0;

    while (helper > 0) {
        helper /= 10;
        stringSize++;
    }

    char * string = (char*) malloc((stringSize + 1) * sizeof(char));
    int position = stringSize - 1;
    string[stringSize] = '\0';

    while (number > 0) {
        int value = number % 10;
        string[position] = digitToChar(value);
        number /= 10;
        position--;
    }
    
    return string;
}

int main(int argc, char ** argv) {
    char* number = itoa(200400);
    printf("%s\n", number);
    free(number);

    number = itoa(1000400);
    printf("%s\n", number);
    free(number);

    number = itoa(20);
    printf("%s\n", number);
    free(number);

    number = itoa(1);
    printf("%s\n", number);
    free(number);
    
}