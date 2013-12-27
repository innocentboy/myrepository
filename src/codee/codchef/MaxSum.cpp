/**
LINK:::http://www.codechef.com/problems/KSUBSUM
*/
/**
INPUT:
3
3 3 4 6
10 20 30
3 1 2 3
10 20 30
4 2 6 10
-20 -15 -10 -15

OUTPUT:
60 50 30
30 30 10
15 -5 -20
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <vector> 

using namespace std;
#define N 10005
#define M 100000000 
int a[N];
int dp[N];

multiset<int> st;
multiset<int>::iterator it;


class mycomparison
{
  bool reverse;
public:
  mycomparison(const bool& revparam=true)
    {reverse=revparam;}
  bool operator() (const int& lhs, const int&rhs) const
  {
    if (reverse) return (lhs>rhs);
    else return (lhs<rhs);
  }
};

void driver()
{
	printf("\ndriver is running..\n");
	int i,j,k1,k2,k3,n,t;
	int ans1,ans2,ans3;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d",&n,&k1,&k2,&k3);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		priority_queue<int,vector<int>,mycomparison> pq;
		st.insert(0);

		for(i=0;i<n;i++)
		{
			if(i>0)
			dp[i]=dp[i-1]+a[i];
			else
			dp[i]=a[i];
			for(it=st.begin();it!=st.end();it++)
			{
			   int val=dp[i]-*it;
			   if(pq.size()<k3)
			   {	
				   pq.push(val);
			   }
			   else if(val>pq.top())
			   {
					pq.pop();
					pq.push(val);
			   }
			   else break;
			}
			st.insert(dp[i]);
		}
	    i=pq.size();
		j=0;
		while(!pq.empty())
		{
		  //printf("\nsize:%d Top:%d  %d:\n",i,pq.top(),i-j);
		  if(i-j==k1) ans1=pq.top();
		  if(i-j==k2) ans2=pq.top();
		  if(i-j==k3) ans3=pq.top();
		  pq.pop();
		  j++;
		}
		printf("ANS:%d %d %d\n",ans1,ans2,ans3);
		st.clear();
	}
}
