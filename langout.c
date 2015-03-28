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
Stack_Pointer += 4;
(*(int *)(&Memory[Frame_Pointer + 8])) = 2;
scanf("%i", ((int*)(&Memory[Frame_Pointer + 8])));
Temp = (*(int *)(&Memory[Frame_Pointer + 8]));
printf("%d\n", Temp);
  return 0;
}
