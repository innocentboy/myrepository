#include<stdio.h>
#include<conio.h>
#include<time.h>
int main()
{
    clock_t t1,t2;
    long int i=0;
    t1=clock();
    for(;i<1000000000;i++);
    t2=clock();
    printf("\nno of ticks:%d  and  time:%f",(t2-t1),(float)(t2-t1)/CLK_TCK);
    getch();
}
