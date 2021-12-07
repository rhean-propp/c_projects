// ask the user to enter the position to read from
//    scanf(" %d", &location);
    
// move to that position and read 15 bytes from the file
//    fseek(position 15);
//    char array[15];
//    fread(array, 1,15,ptr);
    
// present those 15 bytes on the screen
//    printf(values to the screen);

 

#include<stdio.h>
#include<stdlib.h>

 

void usage(int count)
{
    fprintf(stderr, "You entered %d args, but %d required\n", count, 2);
}

 

int main(int argc, char **argv)
{
    if(argc != 2)
    {
        usage(argc); 
        exit(-1);
    }
    FILE *fptr = fopen("myrands.txt", "rb");
    
    if(fptr == NULL)
    {
        fprintf(stderr, "Still no ...\n");
        exit(-2);    
    }
    // int fseek(FILE *stream, long offset, int whence);
    fseek(fptr, strtol(argv[1], NULL, 10), SEEK_SET);
    
    char array[15];
    fread(array, 1, 1, fptr);
    
    for(int count = 0; count < 15; count++)
        fprintf(stdout, "%c ", array[count]);

    printf("\n");    
    fclose(fptr);
}