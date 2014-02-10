/**
http://www.codechef.com/problems/GCD2
*/

/**
Input:
2
2 6
10 11


Output:
2
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
using namespace  std;
#define N 256

char s[N];

int gcd(int a,int b)
{
    if(b==0) return a;
    if(a<b)
     a^=b^=a^b;
    return gcd(b,a%b);
}

int strlenn(char *s)
{
    int i=0;
    while(s[i++]);
    return i-1;
}

int solve(int div)
{
    int i=0,n,ans=0;
    n=strlenn(s);
    for(i=0;i<n;i++)
    {
      ans=ans*10+(s[i]-'0');
      ans%=div;
    }
    return ans;
}


int main()
{
    int i,j,k,a,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%s",&a,s);
        if(a==0)
          printf("%s\n",s);
        else{
        i=solve(a);
        printf("%d\n",gcd(a,i));
        }
    }
    return 0;
}
