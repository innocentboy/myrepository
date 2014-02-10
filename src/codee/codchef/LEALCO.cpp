/**
http://www.codechef.com/problems/LEALCO
*/

/**
NOTE : JUST CHECK THE ALL POSSIBLE SUBSETS OF THE ARRAY, AND BY INCREMENTING THE EACH ELEMENT OF SUBSET OF ARRAY, KEEP CJECKING IT
		WHETHER IT'S , BAD ARRAY OR NOT. IF IT'S NOT RESULTING TO BAD ARRAY THEN COUNT THE NO. OF ELEMENTS IN THE SUBSET AND
		UPDATE THE ANSWER IF THE CURRENT SUBSET SIZE IS SMALLER THAN THE ANSWER.
		WE WOULD KEEP THE DIFFERENT SUBSET OF ARRAY, BY MASKING.
		IF AFTER APPLYING ALL THE SUBSET , WE ARE NOT GETTING THE GOOD ARRAY FOR ANY ONE , THEN THE ANSWER WOULD BE -1.
*/

/**
Input:
4
5 3 2
1 3 1 2 1
5 3 3
7 7 7 7 7
5 3 3
7 7 7 8 8
4 3 1
1 3 1 2

Output:
0
1
1
-1

*/

#include<cstdio>
#include<cmath>
#include<cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define N 25

int r[N];
int newr[N];

bool checkArrest(int n,int k,int m)
{
    int i,j,c=0;
    for(i=0;i<=n-k;i++)
    {
        c=0;
        int maxx=-1;
        for(j=i;j<i+k;j++)
        {
            maxx=max(maxx,newr[j]);
        }
        for(j=i;j<i+k;j++)
        {
            if(maxx==newr[j]) c++;
        }
        if(c>=m) return true;
    }
    return false;
}

//Getting No. of set bites.
int setBits(int n)
{
    int i=0;
    while(n>0)
    {
        i++;
        n-=n&-n;
    }
    return i;
}

int main()
{
    int i,j,k,n,t,m;
    scanf("%d",&t);
    while(t--)
    {
        int maxx=99999;
        scanf("%d%d%d",&n,&k,&m);
        for(i=0;i<n;i++)
            scanf("%d",&r[i]);
        int mask=1<<n;
        for(i=0;i<mask;i++)
        {
            for(j=0;j<n;j++)
            {
                if(i&(1<<j))
                    newr[j]=r[j]+1;

                else
                    newr[j]=r[j];
            }

            if(!checkArrest(n,k,m))
            {
                int setbits=setBits(i);
                if(setbits<maxx)
                    maxx=setbits;
            }
        }
        if(maxx!=99999)
            printf("%d\n",maxx);
        else
            printf("-1\n");
    }

	return 0;
}
