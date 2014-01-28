/**
http://www.codechef.com/problems/PPTEST
NOTE: It's similare to 0-1 knapsack problem.
*/

/**
INPUT:
1
3 7
1 2 3
2 3 5
3 3 3

OUTPUT:
11

*/

#include<cstdio>
#include<iostream>
#include<algorithm>
#define N 105

using namespace std;

int c[N],p[N],t[N];
int pt[N];
int dp[N][N];

int main()
{
    int i,j,k,test,n,w;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d%d",&n,&w);
        //reset the dp array;
        for(i=0;i<=w;i++)
          for(j=0;j<=n;j++)
            dp[i][j]=0;

        for(i=0;i<n;i++)
          scanf("%d%d%d",&c[i],&p[i],&t[i]);
        for(i=0;i<n;i++)
            pt[i]=p[i]*c[i];

        //calculate the best by knapsack problem.
        for(i=0;i<=w;i++)
        {
            for(j=0;j<n;j++)
            {
                if(j==0){
                   dp[i][j]=(t[j]<=i)?pt[j]:0;
                   continue;
                }
                   if(i-t[j]>=0&&dp[i][j]<dp[i-t[j]][j-1]+pt[j])
                       dp[i][j]=max(dp[i][j-1],dp[i-t[j]][j-1]+pt[j]);
                   else
                       dp[i][j]=dp[i][j-1];
            }
        }
        printf("%d\n",dp[w][n-1]);

    }

    return 0;
}
