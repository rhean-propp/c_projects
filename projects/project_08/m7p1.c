#include<stdio.h>
#include<stdlib.h>

// Look into rewind(ptr); It's super useful for this program.

// feof() - tests the end of file indicator
// rewind() - sets the cursor(indicator) to the beginning of the file.

int main()
{
    float val = 0;
    unsigned long numberOfFloats = 0;
    unsigned long numberAbove60 = 0;
    unsigned long numberBelow60 = 0;

    FILE *ptrNumbers = fopen("numbers.bin", "rb");      // This file stores all floating point nubmers between 0.00 and 100.00
    FILE *ptrAbove = fopen("above60.txt", "w");        // This file stores floating point numbers above 60.
    FILE *ptrBelow = fopen("below60.txt","w");         // This file stores floating point numbers below 60.

    if(!ptrNumbers || !ptrAbove || !ptrBelow)                           // Test to see if the file opened properly.
    {
        printf("There was an error opening one of the files.\n");       // Print error.
        exit(-1);                                                       // Exit program.
    }

    while(!feof(ptrNumbers))                            // Execute the loop until the file indicator reaches the end of the file.
    {
        fread(&val, sizeof(float), 1, ptrNumbers);      // Read the value at the indicator with the size of the float.
        numberOfFloats++;

        if(val > 60)
        {
            fprintf(ptrAbove, "Position: %lu\tNum: %.2f\n", numberOfFloats, val);
            //fwrite(&val, sizeof(float), 1, ptrAbove);
            numberAbove60++;
        }
        else
        {
            fprintf(ptrBelow, "Position: %lu\tNum: %.2f\n", numberOfFloats, val);
            //fwrite(&val, sizeof(float), 1, ptrBelow);
            numberBelow60++;
        }
    }

    printf("numbers.bin\tcontains %lu numbers.\nabove.bin\tcontains %lu numbers.\nbelow.bin\tcontains %lu numbers.\n", numberOfFloats, numberAbove60, numberBelow60);

    fclose(ptrNumbers);     // Close numbers.bin
    fclose(ptrBelow);       // Close below60.txt
    fclose(ptrAbove);       // Close above60.txt

    return 0;
}
