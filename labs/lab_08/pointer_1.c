#include<stdio.h>

void main() {

    // 
    int *ptrint;
    char *ptrchar;
    char val = 'A';
    ptrchar = &val;
    float *ptrflt;
    double *ptrdbl;
    long *ptrlng;

    printf("sizeof ptrint: %ld address of ptrint:\t%p\n", sizeof(ptrint), &ptrint);
    printf("sizeof ptrint: %ld address of ptrchar:\t%p value of ptrchr: %p address of val: %p\n", sizeof(ptrchar), &ptrchar, ptrchar, &val);
    printf("sizeof ptrint: %ld address of ptrflt:\t%p\n", sizeof(ptrflt), &ptrflt);
    printf("sizeof ptrint: %ld address of ptrdbl:\t%p\n", sizeof(ptrdbl), &ptrdbl);
    printf("sizeof ptrint: %ld address of ptrlng:\t%p\n", sizeof(ptrlng), &ptrlng);

}
