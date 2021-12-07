#include<stdio.h>


int main()
{
    char mystring[20] = "Wow";

    sprintf(mystring, "%s0h%sReally", "str1", "str2");

    // A variantion of the printf, to print the result into another string desintation instead of stdout.
    // scanf then sptrintf to store your filename in a variable
    // man sprintf

    printf("This is so cool: %s\n", mystring);

    FILE *fptr = fopen(myfilename, "w");

    

}