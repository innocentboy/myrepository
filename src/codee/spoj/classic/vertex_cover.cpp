#include<cstdio>
#include<algorithm>
#include<vector>
#define N 100005
#define include 1
#define pb(a) push_back(a)
using namespace std;
vector<int> graph[N];
int dp[2][N],n;
void dfs(int s,int p)
{
int i,j,k,t;
for(i=0;i<graph[s].size();i++)
{
if(graph[s][i]!=p)
dfs(graph[s][i],s);
}
for(i=0;i<graph[s].size();i++)
{
if(graph[s][i]!=p){
dp[include][s]+=dp[!include][graph[s][i]];
dp[!include][s]+=min(dp[!include][graph[s][i]],dp[include][graph[s][i]]);
}
}
dp[!include][s]=dp[!include][s]+1;
return ;
}


int main()
{
int i,j,k,n,s,d;
scanf("%d",&n);
for(i=1;i<n;i++)
{
scanf("%d%d",&s,&d);
graph[s].pb(d);
graph[d].pb(s);
}
dfs(1,0);
/*for(i=1;i<=n;i++)
{
printf("%d %d\n",dp[!include][i],dp[include][i]);
}*/
printf("%d\n",min(dp[!include][1],dp[include][1]));
return 0;
}
