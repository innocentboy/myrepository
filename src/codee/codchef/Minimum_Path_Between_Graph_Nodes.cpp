/**
This file implements the algorithm of FLOYD WARSHAL , for finding the All pair shortest path between different
Vertices of the graph.
LINK:::
*/
/**
INPUT:
3 3
0 2 4
1 0 0
2 4 0

#####
3 3
0 1 1
1 2 2
0 2 3

OUTPUT:
0 2 3
2 0 2
3 2 0
*/

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define N 1001
#define MAX 99999999

vector<vector<int>> gr(N,vector<int>(N));
int dp[N][N];

/**
This is the algorithm for implementing the floyd Warshal.
*/
void implementWarshal(vector<vector<int>> &gr,int n)
{
	int i,j,k;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
	{
			dp[i][j]=MAX;
			if(gr[i][j])
				dp[i][j]=gr[i][j];
	}
	for(k=0;k<n;k++)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(i!=j)
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
				else
				dp[i][j]=0;
			}
		}
	}
}

void driver()
{
	printf("\nDriver is running....\n");
	int i,j,k,t,n,e;
	scanf("%d%d",&n,&e);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			//scanf("%d",&k);
			gr[i][j]=0;
		}	
	}
	
	while(e--)
	{
		scanf("%d%d%d",&i,&j,&k);
		gr[i][j]=k;
		gr[j][i]=k;
	}
	

	printf("\nPrint teh graph..\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%d ",gr[i][j]);
		printf("\n");
	}
	

	implementWarshal(gr,n);
	printf("\nPrint the DP array after calculation\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		printf("%d ",dp[i][j]);
		printf("\n");
	}
	scanf("%d",&i);
}
