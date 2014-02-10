/**
http://www.codechef.com/problems/DBOY
*/

/**
NOTE: THIS PROBLEM IS SAME AS MINIMUM COIN EXCHANGE PROBLEM AND WOULD BE SOLVED THROUGH DP.
        DP[I][J]: SUPPOSE IT SHOWS MINIMUM NO OF PATROL FILLING OPERATION WOULD BE REQUIRED
        FOR TRAVLING AT MODT J->DISTANCE BY USING I->PETROLPUMP FILLING.
        SO NEED TO CALCULATE THE SUM OVER ALL REQUIRED DISTANCE BY USING MINIMUM  PETROL FILLING
        AMONG N PETROL PUMPS AS:
            ANS=DP[N][2*H[1]]+DP[N][2*H[2]]+........+DP[N][2*H[N]]
       THIS WILL WORK WITH SAME ANOLOGY THAT , THERE ARE SET OF COINS AR E GIVEN, AND WE HAVE TO
       ACHIEVE THE TARGET SUM BY USING THE MINIMUM NO OF COINS AMONG THE GIVEN SET OF COINS.
*/

/**
Input:

1
4
1 2 3 4
1 4 5 3

Output:

7
*/
#include<cstdio>
#include<cmath>
#include<cstring>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
#define N 505
#define INF 1000000007

int h[N],k[N];

int main()
{
    int i,j,t,n;
    scanf("%d",&t);
    while(t--)
    {
        int maxx=-1;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&h[i]);
            maxx=max(maxx,2*h[i]);
        }
        for(i=0;i<n;i++)
            scanf("%d",&k[i]);

        //sort the array..
        sort(k,k+n);
        int store[maxx+1];
        store[0]=0;
        for(i=1;i<=maxx;i++)
        {
            store[i]=INF;
            for(j=0;j<n;j++)
            {
                if(k[j]>i) break;
                if(store[i]>store[i-k[j]]+1)
                  store[i]=store[i-k[j]]+1;
            }
        }

        int ans=0;
        for(i=0;i<n;i++)
        {
            ans+=store[2*h[i]];
        }

        printf("%d\n",ans);
    }

    return 0;
}
