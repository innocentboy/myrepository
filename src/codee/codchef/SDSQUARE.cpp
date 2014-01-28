/**
http://www.codechef.com/problems/SDSQUARE
*/

/**
Input:
2
1 10
100 10000

Output:
3
9
*/

#include<cstdio>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <stack>
#include <cmath>
#include <sstream>
#define N 105
#define M 1000000007
#define ll long long
using namespace std;

vector<ll> vt;

bool isPerfect_square(ll x)
{
    stringstream ss;
    ss<<x;
    string s=ss.str();
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='0'||s[i]=='1'||s[i]=='4'||s[i]=='9') continue;
        else return false;
    }
    return true;
}

void preprocess()
{
    ll i;
    for(i=1;i<=100001;i++)
    {
        ll xx=i*i;
        if(isPerfect_square(xx))
        {
            vt.push_back(xx);
        }
    }
}

int main()
{
    preprocess();
    //
    int i,j,k,t;
    ll a,b;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld%lld",&a,&b);
        k=lower_bound(vt.begin(),vt.end(),b+1)-lower_bound(vt.begin(),vt.end(),a);
        printf("%d\n",k);
    }

    return 0;
}
