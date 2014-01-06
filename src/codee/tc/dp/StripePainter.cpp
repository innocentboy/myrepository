/**
http://community.topcoder.com/stat?c=problem_statement&pm=1215&rd=4555
*/

/**
INPUT:

ABACADA
RGBGR

OUTPUT:
4
3
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <cmath>
#define N 52
#define M 26

using namespace std;

char s[N];
int dp[50][51][128],n;

int solve()
{

}

int strlenn(char *s)
{
    int i=0;
    while(s[i++]);
    return i-1;
}

int main()
{
    int i,j,k;
    scanf("%s",s);
    printf("\npainting :%s\n",s);
    n=strlenn(s);
    for(i=0;i<=n;i++)
    {
      for(j=0;j<=n;j++)
        for(k=0;k<27;k++)
         dp[i][j][k]=-1;
    }

    return 0;
}
