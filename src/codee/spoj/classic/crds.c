#include<stdio.h>
int main()
{
   int i,j,k,t;
   long long n,l;
   scanf("%d",&t);
   while(t--)
   {
     scanf("%lld",&n);
     l=3*n*n;
     printf("%lld\n",((l+n)/2)%1000007);            
   } 
   getch();
   return 0;    
}
