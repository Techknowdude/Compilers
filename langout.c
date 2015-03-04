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
Stack_Pointer += 8;
(*(int *)(&Memory[0])) = 1;
(*(int *)(&Memory[4])) = 5;
Temp = (*(int *)(&Memory[0]));
printf("%d\n", Temp);
Temp = (*(int *)(&Memory[4]));
printf("%d\n", Temp);
  return 0;
}
