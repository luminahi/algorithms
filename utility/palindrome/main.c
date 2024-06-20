#include <stdio.h>

int isPalindrome(const char* text, int length) {
    int left = 0;
    int right = length - 2;

    while (left < right) {
        if (text[left++] != text[right--]) return 0;
    }

    return 1;
}

int main(int argc, char * argv[]) {
    const char text[] = "rac_e_car";

    if (isPalindrome(text, sizeof(text))) {
        printf("%s is a palindrome\n", text);
    } else {
        printf("%s is not a palindrome\n", text);
    }

    return 0;
}