/**
http://www.codechef.com/problems/ARRGAME2
*/

/**
Input
3
1
3
4
2
2 3
1 4
2
2 4
2 2

Output:
1.000000
1.500000
0.000000

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
#define N 1000005
#define INF 1000000000
#define ull long long

int a[N],b[N];

int main()
{
    int i,j,k,t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(i=0;i<n;i++)
        {
            scanf("%d",&b[i]);
        }
        //now calculate the answer.
    }

    return 0;
}
