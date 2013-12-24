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

/**
 * This is used to build The tree for  giving the answer for different ranges.
 * It uses the almost Complete binary tree  structure similar to the Heap Data structure.
 */
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
/**
 *This is Query function which is used to get the answer for
 * the specified range by I and J. 
 */
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

/**
 * This is the Update function for updating the value of a given index..
 * along with it insures that it will also correct the range vlaue in 
 * the range range M[] array. So that , future values could be reflect through the query
 * function.
 */
 int update(int index,int s,int e,int i,int val)
{
	if(s<=i&&i<=e)
	{
		if(s==i&&e==i)
			return M[index]=val;
		int left,right,m;
		m=(s+e)/2;
		left=update(index*2+1,s,m,i,val);
		right=update(index*2+2,m+1,e,i,val);
		return M[index]=min(left,right);
	}
	else
		return M[index];
}

void driver()
{
	printf("\nInside the driver\n");
	int i,j,k,q,t,n;
	scanf("%d%d",&n,&q);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	build(0,0,n-1);
	while(q--)
	{
		scanf("%d%d",&i,&j);
		i--;j--;
		printf("Ans:%d\n",query(0,i,j,0,n-1));
	}
}
