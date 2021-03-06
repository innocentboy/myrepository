/**
http://www.codechef.com/problems/GANGAAM
*/
/**
INPUT:
3
3 2
1 3
3 5
4 6
4 3
1 8
2 9
3 10
4 11
4 3
1 5
4 9
8 13
12 17

OUTPUT:
1
2
0
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
#define N 205
int s[N],e[N],c[N];


void driver()
{
	//printf("\ndriver of GANGAAM is running..\n");
	int i,j,k,n,x,t,ans=0;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&x);
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&s[i],&e[i]);
		}
		
		//sort the input snapshots of times according to the increasing order of end time.
		//So that it would be easy for us to compare the overlapping timming of snapshots by
		//just considering the starting time of the time snapshots.
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				if(e[j]<e[i])
				{
					int temp;
					temp=s[i];
					s[i]=s[j];
					s[j]=temp;

					temp=e[i];
					e[i]=e[j];
					e[j]=temp;
				}
			}
		}

		//Now traverse the sorted array for finding the Ocerlapped time snapshots.
		for(i=0;i<n;i++)
			c[i]=0;
		ans=0;
		for(i=0;i<n;i++)
		{
			bool flag=false;
			for(j=0;j<=i;j++)
			{
				if(s[i]<=e[j])
					c[j]++;
				if(c[j]==x)
					flag=true;
			}
			if(flag)
			{
				ans++;
				for(j=0;j<=i;j++)
				{
					if(s[i]<=e[j])
					c[j]--;
				}
			}
		}
		printf("%d\n",ans);
	}
}
