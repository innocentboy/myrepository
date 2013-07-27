#include<stdio.h>
#include<conio.h>
#define N 3
int g;
void abc(int );
int main()
{ 
    int i=0;
    for(i;i<6;i++)
    abc(i);
   // extern int g;
    printf(" \n %d",g);
    getch(); 
}

void abc(int i)
{
     // static int s=10;

      printf("%d  ",++g);     
}
