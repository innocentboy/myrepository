#include<stdio.h>
int main()
{
  int i,j,n1,n2,rn1,rn2,t;
  scanf("%d",&t);  
  while(t-->0)
  {
     scanf("%d%d",&n1,&n2); 
     rn1=0;rn2=0;
     while(n1>0)
     {
        rn1=10*rn1+n1%10;
        n1/=10;           
     }
     while(n2>0)
     {
        rn2=10*rn2+n2%10;
        n2/=10;           
     }
     n1=rn1+rn2;
     rn1=0;
     while(n1>0)
     {
        rn1=10*rn1+n1%10;
        n1/=10;           
     }           
     printf("%d\n",rn1);          
  }  
  getch();  
  return 0;    
}
