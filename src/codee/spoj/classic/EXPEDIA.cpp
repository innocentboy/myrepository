/**
http://www.spoj.com/problems/EXPEDI/
*/
/**
INPUT:
1
4
4 4
11 5
15 10
5 2
25 10

OUTPUT:
2
*/
#include <cstdio>
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <map>
#include <queue>
using namespace  std;
#define N 10002
int a[N];

void driver()
{
	//printf("\nExpedia driver is running..\n");
	int i,j,k,n,d,t,p;
	scanf("%d",&t);
	while(t--)
	{
		vector< pair<int,int> > vt;
		priority_queue<int> pq;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&j,&k);
			vt.push_back(make_pair(j,k));
		}
		vt.push_back(make_pair(0,0));
		scanf("%d%d",&d,&p);
		sort(vt.begin(),vt.end());
		int count=0;
		for(i=vt.size()-1;i>=0;i--)
		{
			j=d-vt[i].first;
			while(!pq.empty()&&p<j)
			{
			  count++;	
			  k=pq.top();
			 // printf("\np:%d\n",k);
			  pq.pop();
			  p+=k;
			}
			if(p<j)
				break;
			pq.push(vt[i].second);
			//printf("\n %d top:%d\n",vt[i].first,pq.top());
		}
		if(i>=0)
			printf("-1\n");
		else
			printf("%d\n",count);
	}

}
