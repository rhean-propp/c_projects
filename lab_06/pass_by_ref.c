#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Prototypes
void fillArray(int arr[]); // Pass by reference.
                             // arr will store the address --> &array[0]
                             // arr[] is a refference

void printArray(int arr[]); 

// Main Function

int main() {

    srand(time(NULL));
    int array[100] = {0};
    printArray(array);      // passing the address &array[0]

    fillArray(array);
    // fillArray(&array[0]); // Pass the address of the array. Tell the function where to put the values.
    // This line is equivilent to the line above.

    printArray(array);

    return 0;
}

void fillArray(int arr[]) {         // this arr[] is a reference to the array in main. arr holds the address of array[0] 

    for(int count = 0; count < 100; count++) {

        if(count != 0 && count % 5 == 0)
            printf("\n");

        arr[count] = rand() % 80; // Fills array from 0-79

    }

}

void printArray(int arr[]) {

    for(int count = 0; count < 100; count++) {
        
        printf("arr[%d]: %d\n", count, arr[count]);
    }

}


// Notes:

// Global variables should be avoided.
// Every function has it's own block of memeory.