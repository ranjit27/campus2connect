#include <stdio.h>
#include <string.h>

int isPalindromeAroundX(char str[]) {
    int len = strlen(str);
    int middle = -1;

    for (int i = 0; i < len; i++) {
        if (str[i] == 'X' || str[i] == 'x') {
            middle = i;
            break;
        }
    }

    int i = middle - 1;
    int j = middle + 1;

    while (i >= 0 && j < len) {
        if (str[i] != str[j])
            return 0;
        i--;
        j++;
    }

    return 1;
}

int main() {
    char arr[100];
    printf("Enter string with 'X' as middle: ");
    scanf("%s", arr);

    if (isPalindromeAroundX(arr))
        printf("The string is a palindrome.\n");
    else
        printf("The string is not a palindrome.\n");

    return 0;
}
