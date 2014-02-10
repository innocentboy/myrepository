/**
http://www.codechef.com/problems/PERMUT2
*/

/**
Sample Input

4
1 4 3 2
5
2 3 4 5 1
1
1
0

Sample Output

ambiguous
not ambiguous
ambiguous

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
#define N 100005

int a[N];

int main()
{
    int i,j,k,t,n;
    while(scanf("%d",&n)&&n!=0)
    {
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        bool flag=false;
        for(i=0;i<n;i++)
        {
            if(a[a[i]-1]!=(i+1))
            {
               flag=true;
               break;
            }
        }
        if(flag)
            printf("not ambiguous\n");
        else
            printf("ambiguous\n");
    }

    return 0;
}
