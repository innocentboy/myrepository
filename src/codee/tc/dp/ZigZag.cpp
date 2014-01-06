/**
ZIGZAG
http://community.topcoder.com/stat?c=problem_statement&pm=1259&rd=4493
*/
/**
INPUT:
6
1 7 4 9 2 5

10
1 17 5 10 13 15 10 5 16 8

9
1 2 3 4 5 6 7 8 9

19
70 55 13 2 99 2 80 80 80 80 100 19 7 5 5 5 1000 32 32

1
44
OUTPUT:
6
7
2
8
1
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <cmath>
#define N 52
#define M 101

using namespace std;

int a[N],n;

void solve()
{
    int i,j,k;
    int dp[N][2];
    for(i=0;i<=n;i++)
    {
            for(k=0;k<2;k++)
                dp[i][k]=1;
    }
    for(i=n;i>0;i--)
    {
        for(j=i+1;j<=n;j++)
        {
                int k=a[j-1]-a[i-1];
                if(k>0)
                dp[i][0]=max(dp[i][0],dp[j][1]+1);
                else if(k<0)
                dp[i][1]=max(dp[i][1],dp[j][0]+1);
        }
    }
    printf("\nAns:%d\n",max(dp[1][0],dp[1][1]));
}

int main()
{
    printf("\nzig zag is running\n");
    int i,j,k,t;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    solve();

    return 0;
}
