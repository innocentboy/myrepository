#include<stdio.h>
#define N 100000000
char fact[N];
int main()
{
  int i,j,k,t,m,in,temp=0,zero=0;
  scanf("%d",&t);
  while(t-->0)
  {
     scanf("%d",&in);
     fact[0]=1;
     m=1;
     if(in==1)
     printf("%d",1);
     else
     {            
       for(i=2;i<=in;i++)
       {   
           j=0;
           k=m;              
           while(j<m)
           {  
              temp=fact[j]*i+temp;
              fact[j]=temp%10;
              temp/=10;
              j++;           
           }
           while(temp>0)
           {
              fact[m++]=temp%10;
              temp=temp/10;             
           }              
                       
       }zero=0;
       for(i=m-1;i>=0;i--)
       {                
          printf("%d",fact[i]);
       }printf("\n"); 
     }           
  }  
  getch();  
  return 0;    
}
