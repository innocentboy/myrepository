/*
  integer knapsack problem when we can select only an  item single time.
*/

#include<cstdio>
#include<algorithm>
#define N 100
#define M 1000
using namespace std;
int a[N],v[N],dp[N][M];
int main()
{
    int i,j,k,n;
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;i++){
    scanf("%d%d",&a[i],&v[i]);
    }
    for(i=1;i<=n;i++)
    {
      for(j=1;j<=k;j++)
      {
         if(j-a[i]==0)
         dp[i][j]=v[i];

         if((j-a[i]>0)&&dp[i-1][j]<dp[i-1][j-a[i]]+v[i])
         dp[i][j]=dp[i-1][j-a[i]]+v[i];
         else
         dp[i][j]=max(dp[i-1][j],dp[i][j]);

     }
    }
    printf("\n**********\n");
    for(j=1;j<=k;j++)
    printf("%2d  ",j);
    printf("\n");
    for(i=0;i<=n;i++)
    {
       for(j=0;j<=k;j++)
       {
           printf("%2d ",dp[i][j]);
        }
        printf("\n");
    }
    printf("\n maximum value:%d",dp[n][k]);
    return 0;
}
