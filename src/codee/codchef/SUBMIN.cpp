/**
http://www.codechef.com/FEB14/problems/SUBMIN
*/

/**
Input:
5
4 1 2 3 4
4
3
4
6
1

Output:
2
2
0
8
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
#define N 55
#define M 100000000

int a[N],n;

int dp[N][N];

/**
RMQ DP.
*/
void RMQ_DP()
{
    int i,j,k;
    for(i=0;i<n;i++)
     dp[i][i]=i;
    for (i = 0; i < n; i++)
        for (j = i + 1; j < n; j++)
            if (a[dp[i][j - 1]] < a[j])
                  dp[i][j] = dp[i][j - 1];
            else
                  dp[i][j] = j;
}

int main()
{
    int i,j,k,t,q;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    //Preprocess the array.
    RMQ_DP();
    //Number of queries.
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d",&k);
        //find the number of counting..
        int cnt=0;
        for(i=0;i<n;i++)
        {
           for(j=i;j<n;j++)
           {
              if(a[dp[i][j]]==k)
                cnt++;
            }
        }
        printf("%d\n",cnt);
    }


    return 0;
}
