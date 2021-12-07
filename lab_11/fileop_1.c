#include<stdio.h>

int main() {

    FILE *fileptr = NULL;       // Safety Measure. Protects you from dereferrencing a memory location you shouldn't. Good practice to impliment.

    char content [50];

    // fileptr represents a variable that will hold the address of the FILE data structure
    // FILE data strucutre - abstratction of file used to manipulate physical file
    // required in the fopen function is the name of the file and the mode required to access the file (read, write, append)
    // The name and mode must be character strings
    // You must use open first to open the file -- in order to manipulate the file.
    // Always use double quotes -- Remember this for the tests

    fileptr = fopen("myfile.txt", "r");     // Reads the myfile.txt file.

    fscanf(fileptr, "%[^\n]s", content);

    int returned = 1;

    while (returned != EOF)
    {
        returned = fscanf(fileptr, " %[^\n]s", content);
        fprintf(stderr, "Grabbed: \"%s\" from file \n %d", content, returned);
    }

    //printf("grabbed: %s from file\n", content);
    //fprintf(stderr, "Grabbed: \"%s\" from file\n", content);        // This specifically states the stream to print to

    fclose(fileptr);        // Always a good idea to close your file streams when you're done.

    return 0;
}