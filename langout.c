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
Stack_Pointer += 8;
(*(int *)(&Memory[Frame_Pointer + 0])) = 3;
(*(float *)(&Memory[Frame_Pointer + 4])) = 5.000000;
/* Func call */
/* Pushing FP */
(*(int *)(&Memory[Stack_Pointer])) = Frame_Pointer;
Stack_Pointer += 4;
/* Pushing Parameters */
(*(int *)(&Memory[Stack_Pointer])) = 2;
Stack_Pointer += 4;
Frame_Pointer = Stack_Pointer;
/* Making call */
f1();
/* Deallocating Param space */
Stack_Pointer -= 4;
/* Popping FP */
Stack_Pointer -= 4;
Frame_Pointer = (*(int *)(&Memory[Stack_Pointer]));
(*(float *)(&Memory[Frame_Pointer + 4])) = Temp_F;
Temp_F = (*(float *)(&Memory[Frame_Pointer + 4]));
printf("%6.4f\n", Temp_F);
/* Func call */
/* Pushing FP */
(*(int *)(&Memory[Stack_Pointer])) = Frame_Pointer;
Stack_Pointer += 4;
/* Pushing Parameters */
(*(int *)(&Memory[Stack_Pointer])) = (*(int *)(&Memory[Frame_Pointer + 0]));
Stack_Pointer += 4;
Frame_Pointer = Stack_Pointer;
/* Making call */
f2();
/* Deallocating Param space */
Stack_Pointer -= 4;
/* Popping FP */
Stack_Pointer -= 4;
Frame_Pointer = (*(int *)(&Memory[Stack_Pointer]));
(*(int *)(&Memory[Frame_Pointer + 0])) = Temp;
Temp = (*(int *)(&Memory[Frame_Pointer + 0]));
printf("%d\n", Temp);
/* Func call */
/* Pushing FP */
(*(int *)(&Memory[Stack_Pointer])) = Frame_Pointer;
Stack_Pointer += 4;
/* Pushing Parameters */
(*(float *)(&Memory[Stack_Pointer])) = (*(float *)(&Memory[Frame_Pointer + 4]));
Stack_Pointer += 8;
Frame_Pointer = Stack_Pointer;
/* Making call */
f3();
/* Deallocating Param space */
Stack_Pointer -= 8;
/* Popping FP */
Stack_Pointer -= 4;
Frame_Pointer = (*(int *)(&Memory[Stack_Pointer]));
(*(float *)(&Memory[Frame_Pointer + 4])) = Temp_F;
Temp_F = (*(float *)(&Memory[Frame_Pointer + 4]));
printf("%6.4f\n", Temp_F);
  return 0;
}
int f1()
{
/* Return Node */Temp_F = (*(int *)(&Memory[Frame_Pointer + -4])) * 2.000000;
Temp = (*(int *)(&Memory[Frame_Pointer + -4])) * 2.000000;
/* Deallocate local var space */
}
int f2()
{
// Allocate space for local variables.
Stack_Pointer += 4;
(*(int *)(&Memory[Frame_Pointer + 0])) = (*(int *)(&Memory[Frame_Pointer + -4])) * 3;
/* Return Node */Temp = (*(int *)(&Memory[Frame_Pointer + 0]));
/* Deallocate local var space */
Stack_Pointer -= 4;
}
int f3()
{
// Allocate space for local variables.
Stack_Pointer += 8;
(*(float *)(&Memory[Frame_Pointer + 0])) = (*(float *)(&Memory[Frame_Pointer + -8])) * 2;
/* Return Node */Temp_F = (*(float *)(&Memory[Frame_Pointer + 0]));
Temp = (*(float *)(&Memory[Frame_Pointer + 0]));
/* Deallocate local var space */
Stack_Pointer -= 8;
}
