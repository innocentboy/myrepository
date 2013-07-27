#include<stdio.h>
#define N 10000
#define MOD 1000000007
long long a[3][3]={1,1,0,1,0,0,1,0,1};
long long f[3][1],m;
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
    long long i,j,k,x,y,n,t,temp;
    scanf("%lld",&t);
    while(t--)
    {
      scanf("%lld%lld%lld%lld",&x,&y,&n,&m);
      if(n<=2)
      {
         if(n==1)printf("%lld\n",x%m);
         else printf("%lld\n",(x+y)%m);    
      }
      else{
      initialize();          
      f[0][0]=y%m;f[1][0]=x%m;f[2][0]=x%m;
      multiply(n-1);
      for(i=0;i<3;i++)
      {
          temp=0;
          for(k=0;k<3;k++)
          temp+=a[i][k]*f[k][0];
          a[i][0]=temp;                 
      }
      printf("%lld\n",a[2][0]%m); 
    }
    }
    //scanf("%d",&t);
    return 0;    
}
