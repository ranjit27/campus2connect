#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isPalindrome(const char* str) {
    int len = strlen(str);
    int mid = -1;

    for (int i = 0; i < len; i++) {
        if (str[i] == 'X') {
            mid = i;
            break;
        }
    }

    if (mid == -1) {
        printf("Error: No middle marker 'X' found.\n");
        return false;
    }

    int i = mid - 1;
    int j = mid + 1;

    while (i >= 0 && j < len) {
        if (str[i] != str[j])
            return false;
        i--;
        j++;
    }

    return true;
}

int main() {
    char str[] = "ababaXababa";

    printf("Input: %s\n", str);
    printf("%s\n", isPalindrome(str) ? "Palindrome" : "Not Palindrome");

    return 0;
}