/**
http://www.spoj.com/problems/LIS2/
NICEDAY:
http://www.spoj.com/problems/NICEDAY/
SOL:https://github.com/igrsk/spoj/blob/master/NICEDAY.cpp
BLOG:http://mohamedmosamin.wordpress.com/2013/09/05/spoj-niceday-709-the-day-of-the-competitors/
http://apps.topcoder.com/forums/?module=Thread&threadID=575041&messageID=801760&mc=16&view=tree#801760
*/
/**
INPUT:
8
1 3
3 2
1 1
4 5
6 3
9 9
8 7
7 6

//
3
2 8
4 7
3 9

OUTPUT:
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
using namespace  std;

#define N 100005
#define MAX 1000000002
#define f fisrt
#define s second

typedef pair<int,int> pr;
int dp[N];
vector<pr> vt;

struct compare
{
   bool operator()(const pr&a,const pr&b)
   {
	   if(a.first!=b.first)
		   return a.first<b.first;
	   else
		   return a.second<b.second;
   }
};

set<pr> st;
set<pr>::iterator it;
map<set<pr>::iterator,int> mp;

void driver()
{
	   //printf("\nDriver of LIS2 is running\n");
	   int i,j,k,n,maxlen=0;
	   scanf("%d",&n);
	   for(i=0;i<n;i++)
	   {
	      scanf("%d%d",&j,&k);
		  vt.push_back(make_pair(j,k));
		  dp[i]=-MAX;
	   }
       dp[n]=-MAX;
		for(i=1;i<=n;i++)
		{
			it=st.find(vt[i-1]);
			if(it==st.end())
			{
			
			}
			else
			{
			    if(*it>vt[i-1])
				{
				
				}
				printf("\nd:%d\n",j);
			}
		}
		
	   for(i=0;i<n;i++)
	   {
	     maxlen=max(maxlen,dp[i]);
	   }
	   printf("%d\n",maxlen);
}
