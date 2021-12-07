#include<stdio.h>
#include<stdlib.h>

    // Go to offset 0x35
    // Read a value with fread.
    // location = fread(0x35)
    // Go to offset 0x40
    // read a value for the integer.
    // store the value
    // Read a value for the byte
    // Store the byte
    // Read the number of bytes of location.
    // XOR the bytes in location.
    // Print the result of the XOR operation.

int main()
{
    unsigned char val;
    int offset = 0;
    int location;
    int locationByte;
    int num;
    int numByte;
    int xorOutput;

    FILE *ptr = fopen("final.bin", "rb");

    if(!ptr)                                            // If the file did not open correctly:
    {
        printf("The file did not open!\n");     // Print error
        exit(-1);                                       // Quit the program.
    }

    while(fread(&val, 1, 1, ptr))               // Loop through the file 1 byte at a time.
    {
        if(offset == 35)
        {
            location = val;
            locationByte = sizeof(val);     // Retrieve the byte from location.
        }

        if(offset == 40)
        {
            num = val;              // Get the value for num
            numByte = sizeof(val);     // Retrive byte
        }

        offset++;
    }     

    printf("location byte: %d\nnumByte: %d\n", locationByte, numByte);

    xorOutput = locationByte ^ numByte;

    printf("xorOutput: %d\n", xorOutput);

    return 0;
}
