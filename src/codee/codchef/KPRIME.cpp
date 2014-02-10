/**
http://www.codechef.com/problems/KPRIME
*/
/**
Input
4
2 5 1
4 10 2
14 15 2
2 20 3

Output
4
2
2
0
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
#define N 10000000
#define S 25000

int f[N]={0};
bool prime[N];

//preprocess through SIEVE.
void preprocess()
{
    int i,j;
    f[1]=1;

    for(i=2;i*i<=N;i++)
    {
     if(f[i]==0)
     {
        for(j=i;j<=N;j+=i)
        {
            f[j]++;
        }

     }
    }
}

int main()
{
    preprocess();

    int i,j,k,a,b,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&a,&b,&k);
        int cnt=0;
        for(i=a;i<=b;i++)
        {
            if(f[i]==k) cnt++;
        }
        printf("%d\n",cnt);
    }

    return 0;
}
