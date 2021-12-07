#include<stdio.h>

 

// Function Prototype
// Represents to the compiler that there is a function that has the following signature
// And also that if you see the usage of that function before its declaration to not flag it
// because the function is declared (in another file or later in this file);
int funcClarity(int argI, float argF, char argC);    // Prototype return type, functionname and parameter list.
// parameter list is a placeholder for the arguments sent to the function.

 

int main()
{
    int argInt = 10;
    float argFlt = 3.3;
    char argChar = 'a'; // 95
    // Function call
    // function name(argument list)
    printf("\t[MAIN]: %p %p %p\n", &argInt, &argFlt, &argChar);
    int retval = funcClarity(argInt, argFlt, argChar); // Function CALL
    
    printf("[MAIN]: retval: %d\n", retval);
    
    return 0;
}

 

// Function declaration
// Represents the promised work to be accomplished
// It is what the function will be doing inclusive of all statements required to do that work.
int funcClarity(int argI, float argF, char argC)
{
    printf("\t[funcClarity]: %p %p %p\n", &argI, &argF, &argC);
    printf("[funcClarity]: More code to come: %d %f %x\n", argI, argF, argC);
    
    return(argI+ (int)argF + argC);
}