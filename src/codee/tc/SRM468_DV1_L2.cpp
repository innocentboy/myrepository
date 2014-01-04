/**
http://community.topcoder.com/stat?c=problem_statement&pm=10765&rd=14183
*/

/**
INPUT:
3

14

1

2

10

18

1

10

17

1


5

85739

94847

93893

98392

92840

93802

93830

92790

3

//
3
4 6 8
1 7 4
1
//
3
4 6 8
1 11 4
1
//
3
4 6 8
1 11 4
2

OUTPUT:
//
12
//
//
14
//
//
11
//
14
122365

*/

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <cmath>
#define N 4000004
using namespace std;
int flight[N],road[N];
int n;

int solve(int index,int k,int sum)
{
	int i,j,l,m,ret=9999999999;
	if(index==n-1)
	{
	  j=road[index];
	  if(k>0){
		  i=flight[index];
		  return min(i,j);
	  }
	  return j;
	}
	if(k>0){
		ret=min(ret,min(solve(index+1,k-1,sum+flight[index])+flight[index],solve(index+1,k,flight[index])+road[index]));
		ret=min(ret,solve(index+1,k-1,sum));
	}
	else
	{
		ret=0;
		for(i=index;i<n;i++)
			ret+=road[i];
	}
	return ret;
}

void driver()
{
	printf("\ndriver of king or road is running..\n");
	int i,j,k,l,m;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&road[i]);
	for(i=0;i<n;i++)
		scanf("%d",&flight[i]);
	scanf("%d",&k);
	printf("\nAns:%d\n",solve(0,k,0));
}
