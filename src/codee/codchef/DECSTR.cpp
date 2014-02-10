/**
http://www.codechef.com/problems/DECSTR
*/

/**
Sample Input

2
1
2

Sample Output

ba
cba

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
#define N 100
#define M 100
#define INF 1000000000
#define ull long long

int main()
{
    int i,j,k,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&k);
        i=k/25;k=k%25;
        if(k){
            while(k>=0){
            printf("%c",k+'a');
            k--;
            }
        }
        while(i--)
        {
            for(j=25;j>=0;j--)
              printf("%c",j+'a');
        }
        printf("\n");
    }

    return 0;
}
