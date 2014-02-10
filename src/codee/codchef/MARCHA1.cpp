/**
http://www.codechef.com/problems/MARCHA1
*/
/**

*/
#include <cstdio>
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <map>
#include <cstring>
using namespace  std;
#define N 25
#define S 25000

int a[N];
int dp[N][S];

bool isSubset(int n,int sum)
{
    if(sum==0) return true;
    if(n==0&&sum!=0) return false;
    return (isSubset(n-1,sum)||isSubset(n-1,sum-a[n-1]));
}

int main()
{
	int i,j,k,t,n,m;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		int sum=0;
		for(i=0;i<n;i++)
		{
		  scanf("%d",&a[i]);
		  sum+=a[i];
		}

		//set the DP[][] array.
		for(i=0;i<=n;i++)
		{
		  dp[i][0]=true;
		}
		for(i=1;i<=m;i++)
			dp[0][i]=false;

		//Now calculate the answer.
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				dp[i][j]=dp[i-1][j];
				if(a[i-1]<=j)
                    dp[i][j]=dp[i][j]||(dp[i-1][j-a[i-1]]);
			}
		}

		if(dp[n][m])
			printf("Yes\n");
		else
			printf("No\n");
	}
    return 0;
}
