/**
http://www.codechef.com/COOK42/problems/GAMEAAM
*/
/**
INPUT:
3
1
2 3
2
4 5
5 6
2
2 3
3 5

OUTPUT:
NO
NO
YES
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
#define N 105

int grundy(int a,int b)
{
	if(a>b)
		a^=b^=a^=b;
	if(b%a==0) return (b/a)-1;
	int k=b/a,g=grundy(b%a,a);
	if(g==0)
		return k;
	else if(k<=g)
		return k-1;
	return k;
}

void driver()
{
	//printf("\ndriver of GAMEAAM is running..\n");
	int i,j,k,n,t,a,b;
	scanf("%d",&t);
	while(t--)
	{
		int xorr=0;
		scanf("%d",&n);
		while(n--)
		{
			scanf("%d%d",&a,&b);
			xorr^=grundy(a,b);
		}
		if(xorr)
			printf("YES\n");
		else
			printf("NO\n");
	}
	//return 0;
}
