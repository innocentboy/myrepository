/**
QUICKSUM:
http://community.topcoder.com/tc?module=ProblemDetail&rd=5072&pm=2829
*/
/**
INPUT:
99999
45

1110
3

0123456789
45

9230560001
71

382834
100

OUTPUT:
4
3
8
4
2
*/

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <cmath>
#include <cstring>
#define N 12
#define M 102

int dp[N][M];
char s[N],n;

using namespace std;

int strlenn(char *s)
{
    int i=0;
    while(s[i++]!='\0');
    return i-1;
}

int strToNum(char *s,int i,int j)
{
    int sum=0;
    while(i<=j)
    {
      sum=sum*10+s[i]-'0';
      i++;
    }
    return sum;
}

/**
METHOD 1: this is backtrack method for solving this question.
*/
int minop(int index,int n,int sum)
{
    int i,j,k;
    if(index>=n)
    {
        if(sum==0) return -1;
        return 99;
    }
    else
    {
      if(sum>0)
      {
          int ans=99;
          for(i=index;i<n;i++)
          {
             j=strToNum(s,index,i);
             ans=min(ans,minop(i+1,n,sum-j)+1);
          }
          return ans;
      }
      else
        return 99;
    }
}

/**
METHOD 2:DP
*/

int main()
{
    printf("\nquick sum is running..\n");
    int i,j,k,n,sum;
    scanf("%s",s);
    scanf("%d",&sum);

    n=strlenn(s);
    k=minop(0,n,sum);
    if(k!=99)
        printf("\nAns:%d\n",k);
    else
            printf("\n-1 Slution does not exits.\n");

    return 0;
}
