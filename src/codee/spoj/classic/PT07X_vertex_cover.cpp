#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include<conio.h>
#define MAX 100004
#define pb push_back
using namespace std;
vector<int> G[MAX]; //no. of nodes
int dp[MAX][2];
int dfs(int node,int par,bool sel) //whether last was selected
{
	if(dp[node][sel] != -1)
		return dp[node][sel];
	if(sel==0) //parent wsnt selected
	{
		int ans = 1; //this node has to be selected
		for(int i=0;i<G[node].size();i++)
			if(par != G[node][i])
				ans += dfs(G[node][i],node,1);
		return (dp[node][sel]=ans);
	}
	else
	{
		int ans1 = 1,ans2 = 0;
		for(int i=0;i<G[node].size();i++)
			if(par != G[node][i])
			{
				ans1 += dfs(G[node][i],node,1);
				ans2 += dfs(G[node][i],node,0);
			}
		return (dp[node][sel]=min(ans1,ans2));
	}
}
 
int main()
{
	memset(dp,-1,sizeof dp);
	int N;
	scanf("%d",&N);
	for(int i=0;i<N-1;i++)
	{
		int u,v;
		scanf("%d %d",&u,&v);
		G[u].pb(v);
		G[v].pb(u);
	}
	int ans1 = dfs(1,-1,1);
	int ans2 = dfs(1,-1,0);
	printf("%d\n",min(ans1,ans2));
	getch();
	return 0;
}
