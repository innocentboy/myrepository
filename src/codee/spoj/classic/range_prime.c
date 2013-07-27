#include<stdio.h>
#include<math.h>
#define N 100000
int primes[N];
int gen_primes(int m,int n) 
{ 
       int i,j,t=0,k=0,cnt=2;
       for(i=2;i<=(int)sqrt(n);i++)
       { 
           if(primes[i]==0) 
           for(j=i;j*i<n;j++)
           {
              if((i*j-m)>=0)              
              primes[i*j-m]=1; 
              k=i*j-m;
              if(k>t)
              t=k;
              //////////////
            /*  j=j+cnt;
              if(j==2)
              j++;
              else if(j==3)j=+2;
              else if(cnt==2)cnt=4;  
              else cnt=2;*/
           }
       }
       return t;                
} 
int main()
{
  int i,j,k,t,m=0,n=0,l=0;
  scanf("%d",&t); 
  printf("\n");
  while(t-->0)
  {   printf("\n");
      scanf("%d %d",&m,&n);
      if(m==1) 
      l=gen_primes(m++,n);
      else
      l=gen_primes(m,n);
      for(i=0;i<=l;i++)
      {
         if(primes[i]==0)
         printf("%d\n",i+m); 
         primes[i]=0;                
      }           
      printf("\n");        
  }  
  getch();    
}
