/**
http://www.codechef.com/problems/SPREAD
*/
/**
NOTE: WE NEED TO USE BIT DATA STRUCTURE FOR STORING THE CUMULATIVE SUM OF ALL THE NUMBERS
        OF THE ARRAY FALLING IN THE PARTICULAR RANGE.

INPORTANT: NEVER USE CHAR FOR TAKING THE CHARACTER INPUT, ALWAYS USE THE STRING I.E. CHARACTER ARRAY
            FOR STORING THAT STRING AND THEN  USE IT. OTHERWISE SOME TIMES IT CREATES PROBLEM.
*/

/**
Input:

7 5 0
Q 7
S 1 7 1
Q 3
S 1 3 1
Q 3

Output:

0
1
2

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
#define N 1000006
#define M 1000000007

long long a[N];

/**
code related to bit.
*/
long long read(int idx)
{
    long long sum=0;
    while(idx>0)
    {
        sum+=a[idx];
        idx-=(idx&-idx);
    }
    return sum;
}

void update(int idx,int n,int val)
{
    int i;
    while(idx<=n)
    {
        a[idx]+=val;
        idx+=(idx&-idx);
    }
}


int main()
{
    int i,j,t,m,n;
    int c,k;
    char ch[2];
    int u,v,p;
    scanf("%d%d%d",&n,&m,&c);
    //initialise the bit[] array.
    for(i=1;i<=n;i++) a[i]=0;
    update(1,n,c);
    while(m--)
    {
        scanf("%s",ch);
        if(ch[0]=='S')
        {
             scanf("%d%d%d",&u,&v,&k);
             update(u,n,k);
             update(v+1,n,-k);
        }
        else if(ch[0]=='Q')
        {
            scanf("%d",&i);
            printf("%lld\n",read(i));
        }
    }

    return 0;
}
