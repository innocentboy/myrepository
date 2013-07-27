#include<stdio.h>
#define N 10000004
int arr[N];
void phi(int n)
{
  int i,j=1,k=n; printf("%d ",n);printf("= ");    
  for(i=2;i*i<=n;i++)
  {
    if(n%i==0)
    { 
      while(n%i==0)
      {
        if(j){printf("%d",i);j=0;}           
        else printf(" * %d",i);n/=i;            
      }        
    }                   
  } 
  if(n>1)
  {
         if(j)printf("%d",n);
         else {printf(" * %d",n);}
  }
  printf("\nWith %d marbles, %d different rectangles can be constructed",k,arr[k]+1);
  //printf("\nc:%d",c);   
}
int main()
{
  int i,j,k,t,n;
  for(i=2;i<=sqrt(N);i++)
  {
    for(j=i*i;j<N;j+=i)if(j/i!=i)arr[j]++;                       
  }//printf("nzkzlkslksls\n");
  while(scanf("%d",&n)&&n)
  {
     if(arr[n]==0)
     {
        printf("%d = %d",n,n);           
        printf("\nWith %d marbles, %d different rectangles can be constructed",n,1);           
        printf("\n");continue;
     }                     
     phi(n);
     printf("\n");                        
  }  
  getch();  
  return 0;    
}
