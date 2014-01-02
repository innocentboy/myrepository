/**
http://www.codechef.com/problems/WEIGHT

http://www.codechef.com/viewsolution/771111

########
123-18482
https://mypayroll.paysquare.com
*/

/**
INPUT:
2
10 0
2 1

OUTPUT:
9
17
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <set>
using namespace std;
#define N 22
#define W 222
#define MOD 1000007 

int dp[N][W][11];

/**
METHOD1://Using Top-Down DP approach..
*/
int dfs(int n,int w,int val)
{
	int c=0;
	if(n==0)
	{
		if(w==0) 
			return 1;
		else
			return 0;
	}
	if(w<0) return 0;
	if(dp[n][w][val]!=-1)
		return dp[n][w][val];
	for(int i=0;i<10;i++)
	{
	  c=(c+dfs(n-1,w-abs(val-i),i)%MOD)%MOD;
	}
	return dp[n][w][val]=c;
}

/**
METHOD 2:
By using BUTTOM-UP approach.. 
*/

void driver()
{
	//printf("\ndriver of WWEIGHT is running\n");
	int i,j,k,l,t,n,w;
	//while(t--)
	//{
		/** By using METHOD:1
		scanf("%d%d",&n,&w);
		for(i=0;i<=n;i++)
		{
			for(j=0;j<=w;j++)
				for(k=0;k<10;k++)
					dp[i][j][k]=-1;
		}

		k=0;
		for(i=1;i<10;i++)
		{
		     k=(k+dfs(n-1,w,i)%MOD)%MOD;
		}
		*/

		/**
		BY using METHOD 2:
		*/
		for(i=1;i<10;i++)
			dp[1][0][i]=1;
		for(i=2;i<=N;i++)
		{
		   for(j=0;j<=180;j++)
		   {
			for(k=0;k<10;k++)
				for(l=0;l<10;l++)
				{
					dp[i][j+abs(k-l)][k]=(dp[i][j+abs(k-l)][k]%MOD+dp[i-1][j][l]%MOD)%MOD;
				}
		   }
		}
		scanf("%d",&t);
		while(t--)
		{
			scanf("%d%d",&n,&w);
			k=0;
			for(i=0;i<10;i++)
				k=(k+dp[n][w][i]%MOD)%MOD;
			printf("%d\n",k);
		}
	//}
}
