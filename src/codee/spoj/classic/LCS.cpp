/**
http://www.spoj.com/problems/LCS/
*/
/**
INPUT:
alsdfkjfjkdsal
fdjskalajfkdsla

OUTPUT:
3
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
#define N 250005
char s1[N],s2[N];
int  dp[2][N];

int strlenn(char *s)
{
	int i=0;
    while(s[i++]);
	return i-1;
}

void driver()
{
	printf("\nLCS driver is running..\n");
	int i,j,k,ans=0,n,m;
	scanf("%s%s",s1,s2);
	//printf("\n%s \n%s",s1,s2);

	n=strlenn(s1);
	m=strlenn(s2);

	for(i=0;i<=m;i++)
		dp[0][i]=dp[1][i]=0;

	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(s1[i-1]==s2[j-1]){
			  dp[i&1][j]=dp[(i-1)&1][j-1]+1;
			  ans=max(ans,dp[i&1][j]);	
			}
		  else
			  dp[i&1][j]=0;
		}
	}
	printf("%d\n",ans);
}
