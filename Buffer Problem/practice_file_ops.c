//
// Created by Anish Sapre on 06/07/25.
//
#include <stdio.h>
#include <stdlib.h>

int main() {

    FILE* fptr;

    char data[50] = "ANISHANISHANISHANISHANISHANISH";

    fptr = fopen("Buffer Problem/file.txt", "w");

    // Checking if the file is created
    if (fptr == NULL)
        printf("Not opened");
    else{
        printf("Opened\n");
        fputs(data, fptr);
        fputs("\n", fptr);

        fclose(fptr);
        printf("Data written");
        printf("File closed");
    }
    return 0;
}