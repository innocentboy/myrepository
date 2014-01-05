/**
http://community.topcoder.com/stat?c=problem_statement&pm=8570&rd=12012&rm=269199&cr=7581406
*/
/**
INPUT:
1
5
1 2 3 4 5
1 2 3 4 5
10

{1, 2, 3, 4, 5}

{1, 2, 3, 4, 5}

10


1
5
1 2 3 4 5
1 4 9 16 25
10
OUTPUT:
65
309
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <cmath>
#define N 1000
using namespace std;
long long dp[61][111][111];
int C[61],P[61];
int n;

int solve(int index,int c,int d)
{
	int nowc=c+C[index];
	int nowp=P[index];
	if(index==n-1) return nowc*nowp;
	int m=min(d,nowc);
	int ret=(int)dp[index][c][d];
	if(ret!=-1) return ret;
	ret=0;
	for(int i=0;i<=m;i++)
	{
		ret=max(ret,solve(index+1,i,d-i)+(nowc-i)*nowp);
	}
	dp[index][c][d]=ret;
	return ret;
}

void driver()
{
	printf("\ndriver for strategy is running..\n");
	int i,j,k,t,d;

	for(i=0;i<61;i++)
	{
	  for(j=0;j<111;j++)
		  for(k=0;k<111;k++)
			  dp[i][j][k]=-1;
	}

	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&C[i]);
		for(i=0;i<n;i++)
			scanf("%d",&P[i]);
		scanf("%d",&d);
		printf("\nAns:%d\n",solve(0,0,d));

	}

}
