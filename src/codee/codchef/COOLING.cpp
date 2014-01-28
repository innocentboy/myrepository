/**
http://www.codechef.com/problems/COOLING
*/
/**
Sample input:
2
3
10 30 20
30 10 20
5
9 7 16 4 8
8 3 14 10 10

Sample output:
3
4
 
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
//int main()
void driver()
{
	int i,j,k,t,n;
	int pw[N],mw[N];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&pw[i]);
		for(i=0;i<n;i++)
			scanf("%d",&mw[i]);

		//get the maximum weight Pie from the wight array.
		sort(pw,pw+n);
		sort(mw,mw+n);

	//Now calculate the ans.
		int ans=0;
		for(i=0,j=0;i<n&&j<n;i++)
		{
			while(j<n&&pw[i]>mw[j])
				j++;
			if(j<n)
			{
			  ans++;
			  j++;
			}
		}
		printf("%d\n",ans);
	}

	//return 0;
}
