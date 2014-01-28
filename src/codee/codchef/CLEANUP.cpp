/**
http://www.codechef.com/problems/CLEANUP
*/

/**
Input:
3
6 3
2 4 1
3 2
3 2
8 2
3 8

Output:
3 6
5
1

1 4 6
2 5 7
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
//int main()
void driver()
{
	//printf("\nCLEANUP is running.\n");
	int i,j,k,t,n,m;
	bool b[N];
	scanf("%d",&t);
	while(t--)
	{
		
		scanf("%d%d",&n,&m);
		//reset the Bool array b[];
		for(i=0;i<n;i++)
			b[i]=true;
		for(i=0;i<m;i++)
		{
		  scanf("%d",&j);
		  b[j-1]=false;
		}
		//Now print the array
		int c=0;
		for(i=0;i<n;i++)
		{
		  if(b[i])c++;
		  if(b[i]&&c&1) printf("%d ",i+1);
		}
		printf("\n");

		//
		c=0;
		for(i=0;i<n;i++)
		{
		  if(b[i]) c++;
		  if(b[i]&&!(c&1)) printf("%d ",i+1);
		}
		printf("\n");
	}

	//return 0;
}
