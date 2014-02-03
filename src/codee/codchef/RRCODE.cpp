/**
http://www.codechef.com/problems/RRCODE
*/

/**
NOTE:
		ONCE WE ARE GETTING THE VALUE BY APPLYING THE OPERATOR ON ELEMETS OF N-ELEMENT ARRAY. AFTER THAT WE DON'T NEED TO REPEATE THE
		PROCESS FOR THE K-TIMES.
			BECAUSE WE KNOW THAT:
								M|M=M
								M&M=M
								AND 
								M^M=0 
		SO OUR PROCESS WOULD BE INDEPENDENT OF- K AND WE COULD OUR ANSWER BY JUST APPLYING THE OPERATOR ON N-ELEMENT ARRAY
		FOR ONCE ONLY.
			FOR XOR IF K IS ODD THEN - IT'S ANS .
				OTHERWISE IF IT'S EVEN - ZERO.
*/
/**
Input:
3
3 1 0
1 2 3
XOR
3 1 0
1 2 3
AND
3 1 0
1 2 3
OR
Output:
0
0
3
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
int a[N];
char s[10];

//int main()
void driver()
{
	int i,j,k,t,n;
	int ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&k,&ans);
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		scanf("%s",s);
		if(s[0]=='X')
		{
			if(k&1)
			{
				for(i=0;i<n;i++)
					ans^=a[i];				
			}
			printf("%d\n",ans);

		}
		else if(s[0]=='A')
		{
			for(i=0;k>0&&i<n;i++)
				ans&=a[i];
			printf("%d\n",ans);
		}
		else
		{
			for(i=0;k>0&&i<n;i++)
				ans|=a[i];
			printf("%d\n",ans);
		}
	}

	//return 0;
}
