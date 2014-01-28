/**
http://www.codechef.com/problems/MCHAIRS
*/
/**
Input:
2
1
2

Output:
1
3
*/

#include<cstdio>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <stack>
#define N 105
#define M 1000000007
#define ll long long
using namespace std;

ll getPow(ll a,ll n)
{
    ll i=1;
    if(n<=0) return 1;
    if(n%2==0)
    {
        i=getPow(a,n/2);
        return (i*i)%M;
    }
    else
    {
        i=getPow(a,n-1);
        return (i*a)%M;
    }
}

int main()
{
    int i,j,k,t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        ll ans=getPow(2,n)-1;
        printf("%lld\n",ans);
    }

    return 0;
}
