/**
http://www.codechef.com/problems/DRAGNXOR
*/

/**
Input:
3
3 5 4
5 0 1
4 3 7


Output:
7
16
14
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
#define N 100005
#define M 100
#define INF 1000000000
#define ull long long

int setBits(int n)
{
    int i=0;
    while(n>0)
    {
        i++;
        n-=n&-n;
    }
    return i;
}

void printBinary(int n)
{
    if(n>0)
    {
       printBinary(n/2);
       printf("%d",n%2);
    }
}

int main()
{
    int i,j,a,b,t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&a,&b);
        int x,y;
        x=setBits(a);
        y=setBits(b);
        int p=min(x,n-y)+min(y,n-x);
        int ans=((1<<p)-1)<<n-p;
        printf("\nans:%d\n",ans);
    }


    return 0;
}
