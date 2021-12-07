#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    FILE *fileptr = NULL;
    char content[50];

    /*
        Program that will take user input and write it to a file.
    */

   fileptr = fopen("output.txt", "w");      // Opens the file. Enables write mode.

    // if fileptr contained NULL - this means it contains 0
    // if fileptr contained a real address - this value is anything but 0'
    // if this contains a valid address and then you say !(validAddress) -> 0
    // if the fileptr contains a 0, then you are saying !(0) -> 1

    printf("fileptr: %p !fileptr: %d\n", fileptr, !fileptr);

    if (!fileptr)       // If failed to open the file. // If fileptr == NULL) is the equivilent
    {
        fprintf(stderr, "There was an error\n");
        exit(-1);
    }

    printf(" Please enter a string: ");
    scanf(" %[^\n]s", content);

    // the array content contains "some string"
    // How do we write the string "1: some string" to the file?

    char content2[54] = "1: ";

    strncat(content2, content, 49);

    fputs(content2, fileptr);

    printf(" Please enter a string: ");
    scanf(" %[^\n]s", content);

    fprintf(fileptr, "\n2: %s\n", content);

    fclose(fileptr);
    // When we open a file we create a file descriptor in the operating system.
    // If we don't close the file descriptor after completion, we could leave those file descriptors (FDs) open indefinitely.
    // In a busy system there is a remote chance to run out of file descriptors, therefore remember to close your files.

}