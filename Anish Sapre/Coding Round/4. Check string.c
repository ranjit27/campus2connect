//
// Created by Anish Sapre on 10/07/25.
//
#include <stdio.h>

void check_array(char arr[], int size) {
    for (int i=0; i<size/2; i++) {
        if (arr[i] != arr[size-i-1]) {
            printf("Invalid\n");
            return;
        }
    }
    printf("Valid\n");
    return;
}

int main() {
    char arr1[] = {'a', 'b', 'a', 'X', 'a', 'b', 'a'};
    char arr2[] = {'a', 'a', 'b', 'b', 'a', 'X', 'a', 'b', 'b', 'a', 'a'};
    char arr3[] = {'b', 'a', 'b', 'a', 'b', 'X', 'b', 'a', 'b', 'a', 'b'};
    char arr4[] = {'a', 'b', 'b', 'X', 'a', 'b', 'a'};
    char arr5[] = {'a', 'b', 'a', 'X', 'b', 'b', 'a'};
    char arr6[] = {'a', 'b', 'a', 'X', 'a', 'a', 'b'};
    check_array(arr1, sizeof(arr1) / sizeof(arr1[0]));
    check_array(arr2, sizeof(arr2) / sizeof(arr2[0]));
    check_array(arr3, sizeof(arr3) / sizeof(arr3[0]));
    check_array(arr4, sizeof(arr4) / sizeof(arr4[0]));
    check_array(arr5, sizeof(arr5) / sizeof(arr5[0]));
    check_array(arr6, sizeof(arr6) / sizeof(arr6[0]));




    return 0;
}
