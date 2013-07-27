#include<stdio.h>
#include<conio.h>
int main()
{
    union u{
           int a;
           float b;
           char c[6];
          };
    union u abc,*a;
    a=&abc;
    abc.b=10.5;
    printf("print the values of union...\n"); 
    printf("size of union ...%d  \n %d \n",sizeof(abc),sizeof(a));
    printf("%d %f %s",abc.a,abc.b,abc.c);         
    getch();
}
