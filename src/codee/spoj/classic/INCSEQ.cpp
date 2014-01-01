/**
http://www.spoj.com/problems/INCSEQ/
*/
/**
INPUT:
4 3
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
#define N 100005
int a[N];
int dp[N];

void driver()
{
	printf("\ndriver of incse is running...\n");
	int i,j,k,n,ans=0; 
	scanf("%d%d",&n,&k);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++)
	{
		dp[i]=1;
		for(j=0;j<i;j++)
		{
		  if(a[i]>a[j]&&dp[i]<dp[j]+1&&dp[j]<k)
		  {
		    dp[i]=dp[j]+1;
			if(dp[i]==k)
				ans++;
		  }
		}
	}
	printf("\nAnS:%d\n",ans);
}
