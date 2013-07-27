#include<stdio.h>
#include<conio.h>
static int a=5;
void z();
int main()
{
    printf("%d\n ",a);
    abc();
    z();
    printf("\n value of a in main is: %d",a);
    getch();   
     
    
}
void z()
{
    a=15;
    printf("%d",a);     
     
}
