/**
http://www.codechef.com/problems/BWKNIGHT
*/

/**

Constraints :
1 <= T <= 10000
1 <= N,M <= 100000

INPUT:
3
2 2
2 3
4 5

OUTPUT:
12
26
312
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
//int dp[N];

void driver()
{
	printf("\nBlack and white driver running...\n");
	long long i,j,k,t,n,m;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&m);
		k=(n*m);
		if(n>=2&&m>=2)
		k=k*(k-1)-4*((n-1)*(m-2)+(n-2)*(m-1));
		printf("%lld\n",k);		
	}
}
