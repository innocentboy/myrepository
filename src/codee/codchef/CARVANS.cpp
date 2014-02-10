/**
http://www.codechef.com/problems/CARVANS
*/

/**
NOTE: WE JUST NEED TO KEEP THE VALUE OF MINIMUM CAR SPEED TILL THE POINT OF PROCESSING. IF WE ARE
        GETTING ANY CAR AND IT'S SPEED IS LOWER THAN CURRENT MINIMUM, THEN THAT CAR NEED NOT TO
        REDUCE IT'S SPEED AND IT CAN TRAVERSE WITH IT MAXIMUM SPEED. IF CURRENT CAR HAVING THE SPEED
        GHREATER THAN THE MINIMUM VALUE OF SPEED OF CAR TILL THAT POINT, THEN THAT CAR NEED TO
        SLOW DOWN TO AVOID COLLOISION.
*/

/**
Input:
3
1
10
3
8 3 6
5
4 5 1 2 3

Output:
1
2
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
#include <queue>
using namespace  std;
#define N 10005
#define M 100
#define INF 1000000000
#define ull long long

int a[N];

int main()
{
    int i,j,k,t,n;
    scanf("%d",&t);
    while(t--)
    {
        int ans=1,minn;
        scanf("%d",&n);
        for(i=0;i<n;i++)
         scanf("%d",&a[i]);
        minn=a[0];
        for(j=1;j<n;j++)
        {
            if(a[j]<=minn)
            {
               ans++;
               minn=a[j];
            }
        }
        printf("%d\n",ans);
    }

    return 0;
}
