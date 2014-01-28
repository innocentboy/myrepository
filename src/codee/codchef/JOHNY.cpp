/**
www.codechef.com/NOV13/problems/JOHNY
*/

/**
INPUT:
3
4
1 3 4 2
2
5
1 2 3 9 4
5
5
1 2 3 9 4
1

OUTPUT:
3
4
1
*/

#include<cstdio>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <stack>
#define N 105
using namespace std;
int a[N];

int main()
{
    int i,k,j,t,n;
    scanf("%d",&t);
    while(t--)
    {
            scanf("%d",&n);
            for(i=0;i<n;i++)
                scanf("%d",&a[i]);
            scanf("%d",&k);
            int index=0;
            for(i=0;i<n;i++)
            {
                if(a[i]<=a[k-1])
                index++;
            }
            printf("%d\n",index);
    }

    return 0;
}

