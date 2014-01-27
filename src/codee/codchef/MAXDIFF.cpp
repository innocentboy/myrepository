/**
http://www.codechef.com/problems/MAXDIFF
*/

/**
Input:
2
5 2
8 4 5 2 10
8 3
1 1 1 1 1 1 1 1

Output:
17
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
#define N 1005
#define M 1000000007

int a[N];

//int main()
void driver()
{
	//printf("\nMAXDIFF is running\n");
	int i,j,k,n,t;
	int ans,s1,s2,s;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		s=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			s+=a[i];
		}
		//sort the array..
		sort(a,a+n);
		//Now consider the Both k-group element.
		//For that we would take the smallest and largest K-Numbers in group.
		s1=s2=0;
		for(i=0;i<k;i++)
		{
			s1+=a[i];
			s2+=a[n-i-1];
		}
		ans=max(abs(abs(s-s1)-s1),abs(abs(s-s2)-s2));
		printf("%d\n",ans);
	
	}


	//return 0;
}
