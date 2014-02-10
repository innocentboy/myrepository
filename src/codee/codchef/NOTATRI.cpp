/**
http://www.codechef.com/problems/NOTATRI
*/

/**
NOTE: WE JUST NEED TO FIND OUT THE POSSIBLE nO. OF TRIPLET FROM WHICH TRIANGLE IS NOT POSSIBLE.
        SINCE: WE NOTE THAT IF THE LENGTH OF THREE SIDES OF TRIANGLE IS GIVEN AS: A,B,C
        THEN IF A+B<C THEN IT'S NOT POSSIBLE TO FORM THE TRIANGLE. IF WE CONSIDER A<B<C.
*/

/**
Input:
3
4 2 10
3
1 2 3
4
5 2 9 6
0

Output:
1
0
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
#define N 2005
#define M 100
#define INF 1000000000
#define ull long long

int l[N];

int main()
{
    int i,j,k,t,n;
    while(scanf("%d",&n)&&n!=0)
    {
        for(i=0;i<n;i++)
          scanf("%d",&l[i]);
        //sort the array..
        sort(l,l+n);
        int ans=0;
        //now calculate the answer..
        for(i=0;i<n-2;i++)
        {
          for(j=i+1,k=i+2;k<n&&j<n-1;j++)
          {
               while(k<n&&l[i]+l[j]>=l[k])
                 k++;
              ans+=n-k;
          }
        }
        printf("%d\n",ans);
    }

    return 0;
}
