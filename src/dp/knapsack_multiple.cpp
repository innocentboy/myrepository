/*
  knapsack while we can select an item multiple times..
*/
#include<cstdio>
#include<algorithm>
using namespace std;
#define N 100
#define M 1000
int a[N],v[N],dp[M];
int main()
{
  int i,j,k,n;
  scanf("%d%d",&n,&k);
  for(i=1;i<=n;i++){
  scanf("%d%d",&a[i],&v[i]);
  }
  for(j=1;j<=k;j++)
  {
    for(i=1;i<=n;i++)
    {
      if(a[i]<=j)
      {
          if(j-a[i]==0)
          dp[j]=max(dp[j],v[i]);
          dp[j]=max(dp[j-a[i]]+v[i],dp[j]);
          printf("%d ",dp[j]);
      }
    }
    printf("\n");
  }
  printf("\n maximum value:%d",dp[k]);
  return 0;
}
