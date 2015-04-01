#include <stdio.h>
#define MEM_SIZE 100000
char Memory[MEM_SIZE];
int Frame_Pointer;
int Stack_Pointer;
int Temp;
double Temp_F;
int main() { 
Frame_Pointer=0;
Stack_Pointer=0;
// Allocate space for local variables.
Stack_Pointer += 4;
Stack_Pointer += 4;
Stack_Pointer += 4;
(*(int *)(&Memory[Frame_Pointer + 0])) = 3;
(*(int *)(&Memory[Frame_Pointer + 4])) = 4;
/* Func call */
/* Pushing FP */
(*(int *)(&Memory[Stack_Pointer])) = Frame_Pointer;
Stack_Pointer += 4;
/* Pushing Parameters */
(*(int *)(&Memory[Stack_Pointer])) = (*(int *)(&Memory[Frame_Pointer + 0]));
Stack_Pointer += 4;
Frame_Pointer = Stack_Pointer;
/* Making call */
factorial();
/* Deallocating Param space */
Stack_Pointer -= 4;
/* Popping FP */
Stack_Pointer -= 4;
Frame_Pointer = (*(int *)(&Memory[Stack_Pointer]));
(*(int *)(&Memory[Frame_Pointer + 8])) = Temp;
Temp = (*(int *)(&Memory[Frame_Pointer + 8]));
printf("%d\n", Temp);
/* Func call */
/* Pushing FP */
(*(int *)(&Memory[Stack_Pointer])) = Frame_Pointer;
Stack_Pointer += 4;
/* Pushing Parameters */
(*(int *)(&Memory[Stack_Pointer])) = (*(int *)(&Memory[Frame_Pointer + 4]));
Stack_Pointer += 4;
Frame_Pointer = Stack_Pointer;
/* Making call */
factorial();
/* Deallocating Param space */
Stack_Pointer -= 4;
/* Popping FP */
Stack_Pointer -= 4;
Frame_Pointer = (*(int *)(&Memory[Stack_Pointer]));
(*(int *)(&Memory[Frame_Pointer + 8])) = Temp;
Temp = (*(int *)(&Memory[Frame_Pointer + 8]));
printf("%d\n", Temp);
Temp = (*(int *)(&Memory[Frame_Pointer + 0]));
printf("%d\n", Temp);
Temp = (*(int *)(&Memory[Frame_Pointer + 4]));
printf("%d\n", Temp);
// Free space for local variables.
Stack_Pointer -= 12;
  return 0;
}
int factorial()
{
// Allocate space for local variables.
Stack_Pointer += 4;
(*(int *)(&Memory[Frame_Pointer + 0])) = 1;
if (!((*(int *)(&Memory[Frame_Pointer + -4])))) goto LABEL_2;
// Allocate space for local variables.
Stack_Pointer += 4;
/* Func call */
/* Pushing FP */
(*(int *)(&Memory[Stack_Pointer])) = Frame_Pointer;
Stack_Pointer += 4;
/* Pushing Parameters */
(*(int *)(&Memory[Stack_Pointer])) = (*(int *)(&Memory[Frame_Pointer + -4])) - 1;
Stack_Pointer += 4;
Frame_Pointer = Stack_Pointer;
/* Making call */
factorial();
/* Deallocating Param space */
Stack_Pointer -= 4;
/* Popping FP */
Stack_Pointer -= 4;
Frame_Pointer = (*(int *)(&Memory[Stack_Pointer]));
(*(int *)(&Memory[Frame_Pointer + 4])) = Temp;
(*(int *)(&Memory[Frame_Pointer + 0])) = (*(int *)(&Memory[Frame_Pointer + -4])) * (*(int *)(&Memory[Frame_Pointer + 4]));
// Free space for local variables.
Stack_Pointer -= 4;
LABEL_2:
/* Return Node */Temp = (*(int *)(&Memory[Frame_Pointer + 0]));
/* Deallocate local var space */
Stack_Pointer -= 4;
}
