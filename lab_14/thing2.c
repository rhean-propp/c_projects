#include<stdio.h>
#include<stdlib.h>
 
// Offset mean position relative to 0.
 
int main()
{
    FILE *ptr = fopen("myfile.txt", "rb");
    int count = 0;
    unsigned char val;

    if(!ptr)
    {
        fprintf(stdout, "This didn't work\n");
        exit(-1);
    }

    // fread is reading 1 byte from the file
    // it reads from the file stream associated with ptr
    // it puts the read value into val
    // When fread reaches the end of the file it stops and return a zero because that is the end of the file 
    //  hence this causes the loop to stop
    while(fread(&val, 1, 1, ptr))
    {
        // 1. print the offset; the line below needs to be changed
        printf("%06x ----%02x\n", count, val);
        // 2. Print the bytes from the file, in a loop. make sure the individual bytes are separated by a space
        //      54 12 23 67 23 09 09 90 23 12 11

        // 3. print the characters associated with those bytes in a loop.
        //    T.#g#...#..

        count+=16;
    }

    printf("Done!!!\n");

    fclose(ptr);
}