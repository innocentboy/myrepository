/**
RoadOrFlightEasy:
http://apps.topcoder.com/wiki/display/tc/SRM+468
*/
/**
INPUT:
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
12
14
11

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
vector<int> sparedTime;
int n,k;

/**
METHOD 1:
*/
void withoutDP()
{
    int i,j,l,m;
	int result=0;
    for(i=0;i<n;i++){
        sparedTime.push_back(road[i]-flight[i]);
	}
	for(i=0;i<n;i++)
	result+=road[i];

	sort(sparedTime.rbegin(),sparedTime.rend());
	for(i=0;i<k;i++)
	{
        result-=max(sparedTime[i],0);
    }
    printf("\nAns:%d\n",result);
}

/**
METHOD 2:
*/
int dp[2][N];

int solve(int index,int k,int b)
{
    int i,j;
    if(index==n-1)
    {
        i=road[index];
        j=flight[index];
        if(k>0)
        return dp[0][index]=min(i,j);
        return dp[0][index]=i;
    }
    if(dp[0][index]!=-1) return dp[0][index];
    i=solve(index+1,k-1,0)+flight[index];
    j=solve(index+1,k,0)+road[index];
    if(k>0)
        return dp[0][index]=min(i,j);
    else
        return dp[0][index]=j;
}

void withDP()
{
    int i,j,l,m;
    for(i=0;i<n;i++)
    dp[0][i]=dp[1][i]=-1;
    printf("\nAns:%d\n",min(solve(0,k,1),solve(1,k,0)));

}

int main()
{
    printf("\ndriver of king or road is running..\n");
	int i,j,l,m;
	int result=0;

	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&road[i]);
	for(i=0;i<n;i++)
		scanf("%d",&flight[i]);
	scanf("%d",&k);

    //methdod 1:
    withoutDP();

    //METHOD 2:
    withDP();

    return 0;
}
