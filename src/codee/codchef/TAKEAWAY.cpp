/**
NOTE: BASED ON GAME THEORY. NEED TO FIND THE VALID GRUNDY NUMBER.
LINK:::http://www.codechef.com/problems/TAKEAWAY
*/
/**
Input:
3
1 1
3
2 2
3 3
5 10
5 10 15 20 25


Output:
Nancy
Zeta
Nancy
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
#define N 55
#define M 2050
#define INF 1000000000
#define ull long long

int a[N];
int grundy[M][M];
bool visited[M+20];
/**
WE NEED TO CALCULATE THE GRUNDY NUMBER FOR ALL THE POSSIBLE STATES.
WHEN WE ARE DONE WITH ALL TEH CALCULATUIONS OF GRUNDY NUMBERS.
WHEN WE WOULD GET THE INPUT THEN JUST XOR THE ALL GRUNDY NUMBERS FOR STATES.
IF WE GET NON-ZERO NUMBER THEN  FIRST  PLAYER WIN OTHERWISE IT LOSES.
*/
void preprocessGrundy()
{
    int i,j,k;
    for(i=0;i<M;i++)
        grundy[0][i]=0; //This is losing condition i.e. Non-other states can be generated form
                        //This step, so minimum Grundy Number Given t this state, which possibly
                        //would not be acquired by the reaching states, would be Zero(0).
    //Now calculate the Grundy Number for the rest of the states.
    for(i=0;i<M;i++)
    {
        memset(visited,false,sizeof(visited));
        int minn=0;
        for(j=0;j<=i;j++)
        {
            visited[grundy[i-j][j]]=true;
            while(visited[minn])
                minn++;
            grundy[i][j]=minn;
        }
        for(int j=i+1;j<M;j++) grundy[i][j] = grundy[i][i];
    }
}


int main()
{
    //preprocess.
    preprocessGrundy();
   // printf("\ndone..\n");
    int i,j,k,t,n;
    scanf("%d",&t);
    while(t--)
    {
        int xorr=0;
        scanf("%d%d",&n,&k);
        for(i=0;i<n;i++)
        {
            scanf("%d",&j);
            xorr^=grundy[j][min(j,k)];
        }
        puts(xorr?"Nancy":"Zeta");
    }

    return 0;
}
