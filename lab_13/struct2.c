
#include<stdio.h>
#include<string.h>

// with the typedef keyword; mystruct is not of type struct and can be used
// to declare variables of this type.
// mystruct can be thought of as a custom datatype

typedef struct
{
    int myid;
    char myname[30];
}mystruct;

int main()
{
    mystruct me;

    me.myid = 0x11223344;
    strcpy(me.myname, "minime");

    printf("my id is: %d\n", me.myid);
    printf("my name is: %s\n", me.myname);
}