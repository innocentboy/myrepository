/**
LINK:::http://www.codechef.com/problems/KSUBSUM
*/
/**
INPUT:
3
3 1 2 3
10 20 30
3 3 4 6
10 20 30
4 2 6 10
20 -15 10 -15

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

multiset<int> st;
multiset<int>::iterator it;
priority_queue<int,vector<int>,mycomparison> pq;



int  main()
{
	//printf("\ndriver is running..\n");
	int i,j,k1,k2,k3,n,t,val;;
	int ans1,ans2,ans3;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d",&n,&k1,&k2,&k3);
		st.insert(0);
		dp[0]=0;
		for(i=1;i<=n;i++)
		{
		    scanf("%d",&a[i]);
			dp[i]=dp[i-1]+a[i];
			for(it=st.begin();it!=st.end();it++)
			{
			   val=dp[i]-*it;
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
			if(st.size()<k3)
                st.insert(dp[i]);
			else if(dp[i]<*(st.rbegin()))
			{
                it=st.end();
                it--;
                st.erase(it);
                st.insert(dp[i]);
            }
		}
	    i=pq.size();
		j=0;
		while(!pq.empty())
		{
		  int val=pq.top();
		  if(i-j==k1) ans1=val;
		  else if(i-j==k2) ans2=val;
		  else if(i-j==k3) ans3=val;
		  pq.pop();
		  j++;
		}
		printf("%d %d %d\n",ans1,ans2,ans3);
		st.clear();
	}
	return 0;
}
