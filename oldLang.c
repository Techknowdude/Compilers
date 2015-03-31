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
(*(int *)(&Memory[Frame_Pointer + 0])) = 1;
/* Func call */
/* Pushing FP */
(*(int *)(&Memory[Stack_Pointer])) = Frame_Pointer;
Stack_Pointer += 4;
/* Pushing Parameters */
(*(int *)(&Memory[Stack_Pointer])) = 4;
Stack_Pointer += 8;
(*(int *)(&Memory[Stack_Pointer])) = (*(int *)(&Memory[Frame_Pointer + 0]));
Stack_Pointer += 8;
Frame_Pointer = Stack_Pointer;
/* Making call */
Add();
/* Deallocating Param space */
Stack_Pointer -= 8;
/* Popping FP */
Stack_Pointer -= 4;
Frame_Pointer = (*(int *)(&Memory[Stack_Pointer]));
(*(int *)(&Memory[Frame_Pointer + 0])) = Temp;
Temp = (*(int *)(&Memory[Frame_Pointer + 0]));
printf("%d\n", Temp);
  return 0;
}
int Add()
{
/* Return Node */Temp = (*(int *)(&Memory[Frame_Pointer + -4])) + (*(int *)(&Memory[Frame_Pointer + -8]));
/* Deallocate local var space */
}
