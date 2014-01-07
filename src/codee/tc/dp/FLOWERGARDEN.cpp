/**
FLOWERGARDEN:
http://community.topcoder.com/stat?c=problem_statement&pm=1918&rd=5006
*/

/**
INPUT:
5
5 4 3 2 1
1 1 1 1 1
365 365 365 365 365


5
5 4 3 2 1
1 5 10 15 20
5 10 14 20 25

OUTPUT:
{ 1,  2,  3,  4,  5 }
{ 3,  4,  5,  1,  2 }
*/

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <cmath>
#define N 52
#define M 101

using namespace std;
int flower[N],bloom[N],wilt[N];
int ret[N];
bool used[N];

int main()
{
    printf("\nflower garden is running\n");
    int i,j,k,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&flower[i]);
    for(i=0;i<n;i++)
        scanf("%d",&bloom[i]);
    for(i=0;i<n;i++)
        scanf("%d",&wilt[i]);

     printf("\nsolve the question..\n");
     for(i=0;i<n;i++)
        used[i]=false;

     for(i=0;i<n;i++)
     {
        int best=-1;
        for(j=0;j<n;j++)
        {
            if(!used[j]){
            int b=true;
            for(k=0;k<n;k++)
            {
                if(k!=j&&(!used[k])&&flower[k]<flower[j]&&wilt[k]>=bloom[j]&&wilt[j]>=bloom[k])
                b=false;
            }
            if(b&&(best==-1||flower[j]>flower[best]))
            best=j;
           }
        }
        ret[i]=flower[best];
        used[best]=true;
     }
     printf("\nprint the ret array..\n");
     for(i=0;i<n;i++)
       printf("%d ",ret[i]);

    return 0;
}
