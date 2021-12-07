#include<stdio.h>

// Function Prototype
int funcClarity(int argInt, float argFlt, char argChar);    // Prototype return type, functionname and parameter list.

int main() {
    
    int argInt;
    float argFlt;
    char argChar;
    
    int retval = funcClarity(argInt, argFlt, argChar);
    
    printf("retval: %d\n", retval);
    return 0;
}

// Function declaration
int funcClarity(int argInt, float argFlt, char argChar) {

    printf("More code to come: %d %f %c", argInt, argFlt, argChar);
    
    return(argInt + (int)argFlt + argChar);
}