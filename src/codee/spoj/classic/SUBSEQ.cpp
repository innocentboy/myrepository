/**
http://www.spoj.com/problems/SUBSEQ/
*/
/**
INPUT:
2

13
2 7 1 8 2 8 1 8 2 8 4 5 9

7
2 47 10047 47 1047 47 47


OUTPUT:
3
4
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
#define N 100000000
int a[N];

void driver()
{
	printf("\ndriver of SUBSEQ is running..\n");
	int i,j,k,t,n,ans,sum;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		ans=0;sum=a[0];j=0;
		for(i=1;i<=n;i++)
		{
			while(j<i-1&&sum>47)
				sum-=a[j++];
			if(sum==47)
				ans++;
			if(i<n)
				sum+=a[i];
		}
		printf("%d\n",ans);
	}
}
