// find the sum of two subsets in an array whose difference is minimum... i.e. min|s1-s2|.
// where s1 and s2 are sum of two different subsets.
#include<cstdio>
#include<algorithm>
#define N 100
#define M 10000
using namespace std;
int a[N],dp[N][M],n;
int main()
{
   int i,j,k,sum=0,minn=9999999;
   scanf("%d",&n);
   for(i=1;i<=n;i++)
   {
     scanf("%d",&a[i]);
     sum+=a[i];
   }
   printf("\nsum:%d",sum);
   for(i=1;i<=n;i++)
     for(j=1;j<=sum;j++)
     {
        if(j-a[i]==0)
        dp[i][j]=1;
        k=0;
        if(j-a[i]>0){
        k=dp[i-1][j-a[i]];
        dp[i][j]=max(dp[i-1][j],k);
        }
     }
    printf("\n prin the matrix\n");
    for(i=1;i<=n;i++)
    {
     for(j=1;j<=sum;j++)
     {

        printf("%d ",dp[i-1][j-a[i]]);

    }
    printf("\n");
    }
    k=sum/2;
    for(i=1;i<=n;i++)
    {
      for(j=1;j<=k;j++)
      {
        if(dp[i][j])
        {
          minn=min(minn,sum-2*j);
        }
      }
    }
    printf("\n minimum value :%d",minn);
   return 0;
}
