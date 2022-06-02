#include<stdio.h>
int a=10;//global variable stored in data section
int main()
{
int a=20;//local variable stored in stack section
printf("a=10 /global variable \n a=20 local variable\n");
printf("a=%d\n",a);
}
