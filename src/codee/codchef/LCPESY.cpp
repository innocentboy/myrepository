/**
http://www.codechef.com/FEB14/problems/LCPESY
*/
/**
Input:
4
abcd
xyz
abcd
bcda
aabc
acaa
Codechef
elfedcc

Output:
0
4
3
5
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
#define N 10005

char a[N],b[N];

int strlenn(char *s)
{
    int i=0;
    while(s[i++]);
    return i-1;
}

int main()
{
    int i,j,k,t,an,bn;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s%s",a,b);
        an=strlenn(a);
        bn=strlenn(b);

        int ans=0;
        int dpa[256]={0},dpb[256]={0};
        for(i=0;i<an;i++)
          dpa[a[i]]++;
        for(i=0;i<bn;i++)
          dpb[b[i]]++;
        //traverse the array..
        for(i=0;i<130;i++)
        {
            ans+=min(dpa[i],dpb[i]);
        }
        printf("%d\n",ans);

    }

    return 0;
}
