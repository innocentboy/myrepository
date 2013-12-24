/**
Finding the Min in the given ranges in An Array.
This will be solved possibly by the SegmentTree DataStructure. 
*/
/**
INPUT:
10 5
3 5 2 7 1 4 7 8 3 7
1 5
2 5
6 10
2 9
2 2

OUTPUT:
1
1
3
1
5
*/

#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;
#define N 100
int a[N],M[4*N];

void build(int index,int s,int e)
{
	if(s==e)
	{
		M[index]=a[s];
		return ;
	}
	int m=(s+e)/2;
    build(index*2+1,s,m);
	build(index*2+2,m+1,e);
	M[index]=min(M[index*2+1],M[index*2+2]);
}
int query(int index,int l,int r,int s,int e)
{
	if(l>e||r<s)
		return 99999;
	if(l<=s&&e<=r)
	{
		return M[index];
	}
	int left,right,m;
	m=(s+e)/2;
	left=query(index*2+1,l,r,s,m);
	right=query(index*2+2,l,r,m+1,e);
	return min(left,right);
}


void driver()
{
	printf("\nInside the driver\n");
	int i,j,k,q,t,n;
	scanf("%d%d",&n,&q);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	build(0,0,n-1);
	/*
	printf("\nprintf the build Array..\n");
	for(i=0;i<2*n+2;i++)
		printf("%d %d |",i,M[i]);
	printf("\n");
	*/
	while(q--)
	{
		scanf("%d%d",&i,&j);
		i--;j--;
		printf("Ans:%d\n",query(0,i,j,0,n-1));
	}
}
