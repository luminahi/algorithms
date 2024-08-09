#include <stdio.h>
#include <stdlib.h>

int str_length(const char* string) {
    if (!string) return 0;
    
    int i = 0;
    while (string[i]) i++;
    return i;
}

char* concat(char* dest, const char* src) {
    if (!dest || !src) return NULL;

    const int dest_length = str_length(dest);
    const int src_length = str_length(src);

    int i = 0;

    while (i < src_length) {
        dest[dest_length + i] = src[i];
        i++;
    }

    dest[dest_length + i] = '\0';

    return dest;
}

int main(int argc, char* argv[]) {

    char* string = (char*) malloc(sizeof(char) * 255);
    string[0] = '\0';

    concat(string, "alex");
    concat(string, "sora");
    concat(string, "....");

    printf("%s\n", string);

    free(string);

    return 0;
}