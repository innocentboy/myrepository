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
#define M 1000000007

int dp[N][S];
int a[N];

//int main()
void driver()
{
	printf("\nMARCHA1 is running\n");
	int i,j,k,t,n,m;
	scanf("%d",&t);
	while(t--)
	{
		int sum=0;
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++)
		{
		  scanf("%d",&a[i]);
		  sum+=a[i];
		}
		//set the DP[][] array.
		for(i=0;i<n;i++)
		{
		  dp[i][0]=1;
		}
		for(i=0;i<=sum;i++)
			dp[0][i]=0;

		//Now calculate the answer.
		for(i=0;i<n;i++)
		{
			for(j=1;j<=m;j++)
			{
				if(a[i]==j)
					dp[i][j]=1;
				else
				{
					if(a[i]>j&&i>0)
						k=dp[i-1][j-a[i]];
					else 
						k=0;
					dp[i][j]=max(k,i>0?dp[i-1][j]:0);
				}
			}
		}
		if(dp[n-1][m])
			printf("YES\n");
		else
			printf("NO\n");
	}

	//return 0;
}
