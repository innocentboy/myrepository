/**
http://www.codechef.com/problems/NUKES
*/

/**
Input:
3 1 3
Output:
1 1 0
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
#define M 1000000007

int ans[N];

//int main()
void driver()
{
	int i,j,k,a,t,n;
	  scanf("%d%d%d",&a,&n,&k);
	  n++;
	  //compute the answer.
	  for(i=0;i<k;i++)
	  {
		ans[i]=a%n;
		a=(a/n);
	  }
	  //print the answer array.
	  for(i=0;i<k;i++)
		  printf("%d ",ans[i]);
	  printf("\n");

	//return 0;
}
