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
Stack_Pointer += 12;
Stack_Pointer += 4;
Stack_Pointer += 8;
(*(int *)(&Memory[0])) = 3;
(*(float *)(&Memory[4])) = 5.000000;
(*(float *)(&Memory[4])) = /* Func call */(*(int *)(&Memory[Stack_Pointer])) = Frame_Pointer;
Stack_Pointer += 4;
f1();
Stack_Pointer -= 4;
Frame_Pointer = (*(int *)(&Memory[Stack_Pointer]));
;
Temp_F = (*(float *)(&Memory[4]));
printf("%6.4f\n", Temp_F);
(*(int *)(&Memory[0])) = /* Func call */(*(int *)(&Memory[Stack_Pointer])) = Frame_Pointer;
Stack_Pointer += 4;
f2();
Stack_Pointer -= 4;
Frame_Pointer = (*(int *)(&Memory[Stack_Pointer]));
;
Temp = (*(int *)(&Memory[0]));
printf("%d\n", Temp);
(*(float *)(&Memory[4])) = /* Func call */(*(int *)(&Memory[Stack_Pointer])) = Frame_Pointer;
Stack_Pointer += 4;
f3();
Stack_Pointer -= 4;
Frame_Pointer = (*(int *)(&Memory[Stack_Pointer]));
;
Temp_F = (*(float *)(&Memory[4]));
printf("%6.4f\n", Temp_F);
  return 0;
}
int f1()
{
}
int f2()
{
// Allocate space for local variables.
Stack_Pointer += 4;
Stack_Pointer += 4;
(*(int *)(&Memory[4])) = (*(int *)(&Memory[0])) * 3;
}
int f3()
{
// Allocate space for local variables.
Stack_Pointer += 8;
Stack_Pointer += 8;
(*(float *)(&Memory[8])) = (*(float *)(&Memory[0])) * 2;
}
