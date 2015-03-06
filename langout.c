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
(*(int *)(&Memory[0])) = 3;
(*(float *)(&Memory[4])) = 5.000000;
(*(float *)(&Memory[4])) = ;
Temp_F = (*(float *)(&Memory[4]));
printf("%6.4f\n", Temp_F);
(*(int *)(&Memory[0])) = ;
Temp = (*(int *)(&Memory[0]));
printf("%d\n", Temp);
(*(float *)(&Memory[4])) = ;
Temp_F = (*(float *)(&Memory[4]));
printf("%6.4f\n", Temp_F);
  return 0;
}
