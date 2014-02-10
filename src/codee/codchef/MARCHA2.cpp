/**
http://www.codechef.com/problems/MARCHA2
*/

/**
Input:
2
3
0 1 2
3
0 0 3

Output:
Yes
No
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

int main()
{
    int i,j,k,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&k);
        bool flag=false;
        /**Represents the Maximum No. of possible leavs at that level.*/

        int leafs=1;
        while(k--)
        {
            /** i contains the value of leaves at this level.
            */
           scanf("%d",&i);

           /**
           IT CHECKS WHETHER THE GIVEN NO OF LEAFS(I) DOES NOT EXCEEDS WITH THE POSSIBLE NO OF
           LEAFS(LEAFS) VALUE AT THAT LEVEL.
           */
           if(i>leafs)
           {
             flag=true;
           }
           /**No. of possible leafs at  next level.
           Sicne we have i number of leaves at this level and maximum no of leaf in the
           LEAFS variable. Then Maximum no. of possible at next level would be.. Value of
           current maximum leafs - value of leafs at that level, multiply by 2.
           Since each node could either be ended at leafs or could be having two child from
           it.
           IN THE END IF WE HAVING SOME VALUE IN THE LEAFS VARIABLE OR, WE ARE HAVING THE TRUE VALUE
           IN THE FLAG VARIABLE , IT MEANS THAT SOME LEVEL DOES NOT STAISFIED THE VALUE OF
           NO OF POSSIBLE LEAFS AT THAT LEVEL.
           */
           leafs=(leafs-i)*2;
        }
        if(flag||leafs)
          printf("No\n");
        else
          printf("Yes\n");
    }

    return 0;
}
