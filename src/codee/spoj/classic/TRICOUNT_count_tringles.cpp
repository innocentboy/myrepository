#include<cstdio>
#define N 1000005
long long dp[2][N];
void preprocess()
{
  int i,j,k;for(i=1;i<N;i++){dp[0][i]=dp[0][i-1]+i;dp[1][i]=dp[1][i-1]+dp[0][i];}}
int main()
{ preprocess();int i,j,t,n;long long ans=0;
  scanf("%d",&t);while(t--){ans=1;scanf("%d",&n);ans=n;ans*=n;ans+=dp[1][n-1];printf("%lld\n",ans);}return 0;}
