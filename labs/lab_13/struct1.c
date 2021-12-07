#include<stdio.h>

typedef struct myStudent{  // Notice the use typedef of struct myStudent

  char name[30];

  int studentID;

  char sem1_classes[5][30];

  float scores[5][30];

}Student;                            // this last line is the secret sauce, struct myStudent

                                           // is now equivalent to Student

 

int main()

{

  Student student1; // declaring a new student struct variable

}