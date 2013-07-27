#include<stdio.h>
#include<conio.h>
int phi(int n)
{
    int result=n,i,j;
    for(i=2;i*i<=n;i++)
    {
       if(n%i==0)result-=result/i;
       while(n%i==0)n/=i;                   
    }
    if(n>1)result-=result/n;
    return result;    
}
int main()
{
    int i,j,k,n,t;
    scanf("%d",&t);
    while(t--)
    {
       scanf("%d",&n);
       printf("%d\n",phi(n));       
    }
    getch();
    return 0;
}
