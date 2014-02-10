/**
http://www.codechef.com/problems/BESTBATS
*/
/**
NOTE: WE JUST TO NEED SORT THE ARRAY FIRST. SINCE WE WANT TO MAKE THE K-PERMUTATION OF BATSMAN
        HAVING MAXIMUM SCORE AFTER SUMMING ALL THE SCORES OF THE BATSMANS.
        SO, WE NEED TO FIND THE THOSE SCORES WHICH ARE SAME AND FALLS AFTER TAKING THOSE K-MAX
        SUM SCORE. THEN WE JUST NEED TO TAKE THE COMBINATION VALUE AMONG THOSE SAME MAX-SUM
        SCORE VALUE.
*/

/**
Input:
3
1 2 3 4 5 6 7 8 9 10 11
3
2 5 1 2 4 1 6 5 2 2 1
6
1 1 1 1 1 1 1 1 1 1 1
11

Output:
1
6
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
#define N 100005
#define M 100
#define INF 1000000000
#define ull long long

int a[12];

int fact(int n)
{
    if(n<=1) return 1;
    return n*fact(n-1);
}

int comb(int n,int r)
{
    return fact(n)/(fact(r)*fact(n-r));
}

int main()
{
    int i,j,k,t,n;
    scanf("%d",&t);
    while(t--)
    {
         for(i=0;i<11;i++)
         scanf("%d",&a[i]);
         sort(a,a+11);
         scanf("%d",&k);
         i=0;j=0;
         n=11;
         for(int temp=n-k;temp<n;temp++)
          if(a[temp]==a[n-k])
            i++;
         for(int temp=n-k-1;temp>=0;temp--)
           if(a[temp]==a[n-k])
            j++;
         printf("%d\n",comb(i+j,j));
    }

    return 0;
}
