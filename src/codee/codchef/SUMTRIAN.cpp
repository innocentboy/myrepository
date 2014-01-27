/**
http://www.codechef.com/problems/SUMTRIAN
*/

/*
INPUT:
2
3
1
2 1
1 2 3
4 
1 
1 2 
4 1 2
2 3 1 1 

OUTPUT:
5
9

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
#define N 105
#define M 1000000007
//int main()
void driver()
{
	int i,j,k,t,n;
	scanf("%d",&t);
	while(t--)
	{
		int a[N][N];
		int dp[N][N];

		scanf("%d",&n);
		k=1;
		for(i=0;i<n;i++)
		{
			for(j=0;j<k;j++)
			scanf("%d",&a[i][j]);
			k++;
		}

		//Initialise the Dp[][] array.
		for(i=0;i<=n;i++)
			dp[n][i]=0;

		//start the DP[][] array calculation.
		for(i=n-1;i>=0;i--)
		{
			for(j=0;j<=i;j++)
			{
				dp[i][j]=max(dp[i+1][j],dp[i+1][j+1])+a[i][j];
			}
		}
		printf("%d\n",dp[0][0]);
	}

	//return 0;
}
