#include<stdio.h>
#define N 
void fun()
{
     printf("this function is called before the mian\n");     
}
struct bit_field
{
   unsigned int a:1;
   int b:3;
  unsigned int c:28;       
}v={1,2,8};
int main()
{
  /*  int n;
    printf("enter the value of n\n"); 
    scanf("%d",&n);
    if((n-1)%4==0)
    printf("Alice will win this match..");
    else
    printf("Bobb will win the match...");   */
 /*   #ifdef N
         printf("N is defined already..\n");
    #endif
    #ifdef N
         printf("N is defined second time..\n");
    #endif
         printf("it is not defined");      */ 
   // printf("\n%d  %d %c",32<<1,-32<<1,-48);        
   printf("%d  %d   %d   %d",sizeof(v),v.a,v.b,v.c);  
    getch();
}
