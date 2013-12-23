/**
PROBLEM LINK:
http://www.codechef.com/DEC13/problems/MARBLEGF
*/

/**
INPUT:
5 3
1000 1002 1003 1004 1005
S 0 2
G 0 3
S 0 2

OUTPUT:
3005
3008
*/

#include <cstdio>
#include <iostream>
using namespace std;

#define N 1000004
int a[N];
int dp[N];

/**
Code related to the BIT.
*/
int read(int idx)
{
	int sum=0;
	while(idx>0)
	{
		sum+=dp[idx];
		idx-=idx&(-idx);
	}
	return sum;
}
void update(int idx,int maxVal,int val)
{
	while(idx<=maxVal)
	{
		dp[idx]+=val;
		idx+=idx&(-idx);
	}
}

void driver()
{
	int i,j,k,n,q;
	char c;
	scanf("%d%d",&n,&q);
	for(i=0;i<n;i++){
		scanf("%d",&k);
		update(i+1,n,k);
	}
	while(q--)
	{
		fflush(stdin);
		scanf("%c%d%d",&c,&i,&j);
		if(c=='S')
		{
			if(i>0)
				printf("%d\n",read(j+1)-read(i+1));
			else
				printf("%d\n",read(j+1));
		}
		else
		{
			if(c=='G')
				update(i+1,n,j);
			else
				update(i+1,n,-j);
		}
	}
}
