//
// Created by Anish Sapre on 06/07/25.
//
#include <stdio.h>
#include <stdlib.h>

int main() {

    // File pointer
    FILE* fptr;

    // Get the data to be written in file
    char data[50] = "ANISHANISHANISHANISHANISHANISH";

    // Creating file using fopen()
    // with access mode "w"
    fptr = fopen("Buffer Problem/file.txt", "w");

    // Checking if the file is created
    if (fptr == NULL)
        printf("The file is not opened.");
    else{
        printf("The file is now opened.\n");
        fputs(data, fptr);
        fputs("\n", fptr);

        // Closing the file using fclose()
        fclose(fptr);
        printf("Data successfully written in file "
               "file.txt\n");
        printf("The file is now closed.");
    }
    return 0;
}