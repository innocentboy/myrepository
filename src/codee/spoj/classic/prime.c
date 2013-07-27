#include<stdio.h>
#include<math.h>
#define N 9223372036854775807
int main()
{
  int i,j,k,t,f=1,inc=2;
  long long in;
  scanf("%d",&t);
  while(t-->0)
  {
      scanf("%lld",&in);
      f=in>1;
      k=(int)sqrt(in);
      for(i=2;(i<=k)&&f;)
      {
         f=(in%i);
         if(i==2)i++;
         else if(i==3)i=i+2;
         else
         {
             i=i+inc;
             if(inc==2)
             inc=4;
             else
             inc=2;
         }    
      }                  
      if(f)
      printf("\nYES");
      else
      printf("\nNO");           
      f=1;        
  }
  getch();  
  return 0;    
}
