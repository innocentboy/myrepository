#include<stdio.h>
#define N 10000
#define m 1000000007
long long a[3][3]={1,1,0,1,0,0,1,0,1};
long long f[3][1];
void initialize()
{
    a[0][0]=1;a[0][1]=1;a[0][2]=0;
    a[1][0]=1;a[1][1]=0;a[1][2]=0;
    a[2][0]=1;a[2][1]=0;a[2][2]=1;     
}
void mult(long long a[][3],long long b[][3])
{
  long long c[3][3];
  int i,j,k,temp;
  for(i=0;i<3;i++)
  {
    for(j=0;j<3;j++)
    {
      c[i][j]=0;
      for(k=0;k<3;k++)
      c[i][j]=(c[i][j]+((a[i][k]%m)*(b[k][j]%m))%m)%m;              
    }                
  }
  for(i=0;i<3;i++)
     for(j=0;j<3;j++)a[i][j]=c[i][j];
}
void multiply(int n)
{  
  long long t[3][3],i,j,k;   
  if(n==2)
  {
    mult(a,a);
    return ;      
  }
  if(n&1)
  {
     for(i=0;i<3;i++)
     for(j=0;j<3;j++)
     t[i][j]=a[i][j];    
     multiply((n-1));mult(a,t);       
  }      
  else
  {
     multiply(n>>1);mult(a,a);
  }
}
int main()
{
    long long i,k,x,y,t,temp,sum1,sum2;
    scanf("%lld",&t);
    f[0][0]=1;f[1][0]=0;f[2][0]=0;
    while(t--)
    {
      scanf("%lld%lld",&x,&y);
      x=(x+1);y=(y+1);
      if(x<=3)
      {
         if(x==1)sum1=0;else if(x==2) sum1=0;else sum1=1;   
      }
      else{
      initialize();          
      multiply(x-2);
     for(i=0;i<3;i++)
      {
          temp=0;
          for(k=0;k<3;k++)
          temp+=a[i][k]*f[k][0];
          a[i][0]=temp;                 
      }
      sum1=(a[2][0])%m;printf("%lld ",sum1);
    }
    if(y<=2)
      {
         if(y==1)sum2=0;else sum2=1;   
      }
      else{
      initialize();          
      multiply(y-1);
     for(i=0;i<3;i++)
      {
          temp=0;
          for(k=0;k<3;k++)
          temp+=a[i][k]*f[k][0];
          a[i][0]=temp;                 
      }
      sum2=a[2][0]%m;printf("%lld  ",sum2);
    }
    printf("%lld\n",(sum2-sum1)%m);
    }
    //scanf("%d",&t);
    return 0;    
}

