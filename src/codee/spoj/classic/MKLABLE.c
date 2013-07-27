#include<stdio.h>
#include<math.h>
int poww(int n,int power)
{
   int i=1;
   while(power--)
   {
      i*=n;              
   }    
   return i;
}
int main()
{
    
  int i,j,k=1,n;
  while(scanf("%d",&n)&&n)
  {
    if(n==1)printf("Case %d, N = 2, # of different labelings = 1\n",k++);
    else printf("Case %d, N = %d, # of different labelings = %d\n",k++,n,poww(n,n-2));                        
  } 
  return 0;    
}
