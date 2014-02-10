/**
http://www.codechef.com/problems/RRECIPE
*/

/**
Input:
5
?
??
ab?
a?c
aba

Output:
26
26
1
0
1
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
#include <queue>
using namespace  std;
#define N 1000005
#define M 1000000007
#define INF 1000000000
#define ull long long

char s[N];

int strlenn(char *s)
{
    int i=0;
    while(s[i++]);
    return i-1;
}

int main()
{
    int i,j,k,t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",s);
        n=strlenn(s);
        long long ans=1;
        i=0;j=n-1;
        while(i<=j)
        {
           if(s[i]=='?'&&s[j]=='?')
             ans=(ans*26)%M;
           else if(s[i]!='?'&&s[j]!='?'&&s[i]!=s[j])
           {
             ans=0;
             break;
           }
           i++;j--;
        }
        printf("%lld\n",ans);
    }

    return 0;
}
