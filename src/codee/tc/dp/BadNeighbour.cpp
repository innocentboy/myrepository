/**
BADNEIGHBOURS:
http://community.topcoder.com/stat?c=problem_statement&pm=2402&rd=5009
*/
/**
INPUT:
6
10 3 2 5 7 8

7
7 7 7 7 7 7 7

10
1 2 3 4 5 1 2 3 4 5
OUTPUT:
19
21
16
*/

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <cmath>
#define N 52
#define M 101

int dp[2][N],n,a[N];

using namespace std;

/**
METHOD 1:
*/
int solve(int index,int sel)
{
    int i,j,k;
    if(index>=n) return 0;
    if(index==n-1&&sel==1) return 0;
    else if(index==n-1) return a[index];
    int &ret=dp[sel][index];
    if(ret!=-1) return ret;
    ret=max(solve(index+1,sel),solve(index+2,sel)+a[index]);
    return ret;
}

void solveDP()
{
    int i,j,k;
    for(i=0;i<n;i++)
      for(k=0;k<2;k++)
        dp[k][i]=-1;
    printf("\nAns:%d\n",max(solve(2,1)+a[0],solve(1,0)));
}

int main()
{
    printf("\nbad neighbours are running..\n");
    int i,j,k;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    solveDP();

    return 0;
}
