/**
http://www.geeksforgeeks.org/dynamic-programming-set-28-minimum-insertions-to-form-a-palindrome/
*/

/**

*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#define M 100000007
#define N 1000

using namespace std;

int strlenn(char *s)
{
    int i=0;
    while(s[i++]);
    return i-1;
}

int findMinInsertionsRecursion(char *s,int l,int r)
{
    if(l>r) return M;
    if(l==r) return 0;
    //if()
    if(s[l]==s[r])
      return findMinInsertionsRecursion(s,l+1,r-1);
    return min(findMinInsertionsRecursion(s,l+1,r),findMinInsertionsRecursion(s,l,r-1))+1;
}

int findMinInsertionsDP(char *s,int n)
{
    int i,j,k;
    int dp[n+1][n+1];

    for(i=0;i<=n;i++)
     for(j=0;j<=n;j++)
        dp[i][j]=0;

    for(int gap=1;gap<n;gap++)
    {
      for(i=0,j=gap;j<n;i++,j++)
      {
        if(s[i]==s[j])
           dp[i][j]=dp[i+1][j-1];
        else
           dp[i][j]=min(dp[i+1][j],dp[i][j-1])+1;
      }
    }
    return dp[0][n-1];
}

////////////////////////////////////////////
int findMinInsertionsDP1(char str[], int n)
{
    // Create a table of size n*n. table[i][j] will store
    // minumum number of insertions needed to convert str[i..j]
    // to a palindrome.
    int table[n][n], l, h, gap;

    // Initialize all table entries as 0
    memset(table, 0, sizeof(table));

    // Fill the table
    for (gap = 1; gap < n; ++gap)
        for (l = 0, h = gap; h < n; ++l, ++h)
            table[l][h] = (str[l] == str[h])? table[l+1][h-1] :
                          (min(table[l][h-1], table[l+1][h]) + 1);

    // Return minimum number of insertions for str[0..n-1]
    return table[0][n-1];
}

int main()
{
    char str[] = "kgeeks";
    int n=strlenn(str);
    printf("l:%d\n",n);
    printf("rec:%d  DP:%d  :%d",findMinInsertionsRecursion(str,0,n-1), findMinInsertionsDP(str,n)
                                ,findMinInsertionsDP1(str,n));

    return 0;
}
