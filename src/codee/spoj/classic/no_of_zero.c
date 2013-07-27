#include<stdio.h>
#define N 1000000
int main()
{
    int i,j,k,t,no,zero=0,n;
    scanf("%d",&t);
    while(t-->0)
    {
       zero=0;n=5;         
       scanf("%d",&no);
       while(n<=no)
       {
          zero+=no/n;
          n*=5;          
       }
       printf("\n%d",zero);           
    }
    getch();
   return 0;        
}
