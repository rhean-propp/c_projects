#include<stdio.h>
#include<stdlib.h>

// stdin:   Standard input stream.
// stdout:  Standard output stream.
// stderr:  Standard error.

int main(int argc, char **argv) 
{
    FILE *ptr = fopen("myfile3.bin", "rb");

    int value = 1;

    if (ptr == NULL)
    {
        fprintf(stderr, "File didn't open properly.\n");
        exit(-1);
    }

    if (argc == 2)
    {
        value = (int)strtol(argv[1], NULL, 10);
    }
    else
    {
        value = 15;
    }

    fseek(ptr, value*4, SEEK_SET);  // Skip 4 bytes every time.

    fread(&value, 4, 1, ptr); // Takes out one integer from the file at the location provided.
    printf("value: %d\n", value);

    fclose(ptr);
}