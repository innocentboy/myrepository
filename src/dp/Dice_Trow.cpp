/**
Given n dice each with m faces, numbered from 1 to m, find the number of ways to get sum X. X is
the summation of values on each face when all the dice are thrown.
*/

/**
Function which calcutaes the no of value of finding the value x, by throwing the n dices.
m: different faces of dice (1,2,3,4,5,6...)
n: no of dices.
x: Sum value that we have t get by throwing the dices.
*/

#include<istream>
#include<iostream>
using namespace std;

int findWays(int m,int n,int x)
{
   int dp[n+1][x+1],i,j,k;
   for(i=0;i<=n;i++)
     for(j=0;j<=x;j++)
        dp[i][j]=0;

   for(i=1;i<=m&&i<=x;i++)
     dp[1][i]=1;

   for(i=2;i<=n;i++)
       for(j=1;j<=x;j++)
          for(k=1;k<=m&&k<j;k++)
            dp[i][j]+=dp[i-1][j-k];

    return dp[n][x];
}

int main()
{
    cout << findWays(4, 2, 1) << endl;
    cout << findWays(2, 2, 3) << endl;
    cout << findWays(6, 3, 8) << endl;
    cout << findWays(4, 2, 5) << endl;
    cout << findWays(4, 3, 5) << endl;
    return 0;
}
