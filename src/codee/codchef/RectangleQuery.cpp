/**
PROBLEM LINK:shttp://www.codechef.com/DEC13/problems/RECTQUER
*/
/**
Input:
3
1 2 3
3 2 1
5 6 3
3
1 1 2 3
2 2 2 2
1 1 3 3 

Output:
3
1
5
*/

#include "stdafx.h"
#include <iostream>
#include <cstdio>

#define N 302
int dp[N][N][11];

void driver()
{
	printf("\nInside the driver method..\n");
	int i,j,k,n,x1,x2,y1,y2,q;
	int ans=0;
	scanf("%d",&n);
	for(i=0;i<1;i++)
	{
		for(j=0;j<1;j++)
			for(k=0;k<11;k++)
				dp[i][j][k]=0;
	}
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
	{
			for(k=1;k<11;k++)
				dp[i][j][k]=dp[i-1][j][k]+dp[i][j-1][k]-dp[i-1][j-1][k];
			scanf("%d",&q);
			dp[i][j][q]++;
	}
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		//x1--;y1--;x2--;y2--;
		ans=0;
		for(i=1;i<11;i++)
		{
			if((dp[x2][y2][i]-dp[x2][y1-1][i]-dp[x1-1][y2][i]+dp[x1-1][y1-1][i])>0)
				ans++;
		}
		printf("\nANS:%d\n",ans);
	}

}
