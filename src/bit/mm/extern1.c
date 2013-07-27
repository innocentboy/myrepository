#include<stdio.h>
#include<conio.h>
//int a;   
void abc()
{
       
     extern int a;
     printf("value of a in function abc is %d \n",a);
}
#include"extern.c"
