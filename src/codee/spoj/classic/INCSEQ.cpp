/**
http://www.spoj.com/problems/INCSEQ/
*/
/**
1 N 10,000
1  K 50

INPUT:
6 3
1
2
2
10
15
4
25

4 2
1
2
2
10


OUTPUT:
2
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
#define N 10005
#define K 52
#define M 5000000

int a[N];
int dp[N][K];

void driver()
{
	//printf("\ndriver of incse is running...\n");
	int i,j,l,k,n,ans=0; 
	scanf("%d%d",&n,&k);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++)
	{
		for(j=0;j<=k;j++)
	    dp[i][j]=0;
		dp[i][1]=1;
	}

	for(i=0;i<n;i++)
	{
		for(j=0;j<i;j++)
		{
		  for(l=2;l<=k;l++)
		  {
		    if(a[i]>a[j])
			{
			  if(dp[j][l-1]>0&&dp[i][l]>0)
				  dp[i][l]=(dp[j][l-1]+1)%M;
			  else if(dp[j][l-1]>0)
				  dp[i][l]=(dp[j][l-1])%M;

			}
		  }
		}
		/*
		printf("\nprint the array...\n");
		for(j=0;j<n;j++)
		{
			for(l=1;l<=k;l++)
				printf("%d ",dp[j][l]);
			printf("\n");
		}
		*/
	}	
		ans=0;
		for(i=0;i<n;i++)
		{
			ans=(dp[i][k]+ans)%M;
		}
		printf("%d\n",ans);
}
