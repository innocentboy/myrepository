/**
http://www.codechef.com/problems/HOTEL
*/

/**
NOTE: IN ORDER TO SOLVE THIS QUESTION, WE NEDD TO DIVIDE THE ARRIVAL AND DEPARTURE TIME IN THE
       FORM OF EVENTS, AND CHARACTERISING THE EVENTS ACCIORDING TO THE  ARRIVAL AND DEPARTURE
       TIME BY THE TYPE OF THE EVENTS. WHEN WE ARE GRETTING THE EVENT TYPE OF 1 TYPE , ADD IT
       TO THE BEST THAT SHOWS THE CURRENT BO OF PEOPLE PRESENT IN THE PARTY. IF IT'S BEJTTER THAN
       ALREADY CALCULATED MAXX VALUE THEN UPDATE THE ANSWER ACCORDING TO IT. SAME DO FOR TYPE -1,
       WHEN WE ARE GETTING THIS EVENT , IT MEANS THAT SOMEONE IS LEAVING THE PARTY SO WE NEED
       TO DECREASDE THE NO OF PEOPLE CUURENTLY IN THE PARTY AT THAT INTERVAL OR EVENT.
*/

/**
Sample Input

3
3
1 2 3
4 5 6
5
1 2 3 4 5
2 3 4 5 6
7
13 6 5 8 2 10 12
19 18 6 9 9 11 15

Sample Output

3
1
3

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

int at[N],dt[N];
typedef struct
{
    int time;
    int type;
}Time;

bool compare(const Time &a,const Time &b)
{
    if(a.time!=b.time)
        return a.time<b.time;
    else
        return a.type<b.type;
}

int main()
{
    int i,j,k,t,n;
    scanf("%d",&t);
    while(t--)
    {
        vector<Time> vt;
        scanf("%d",&n);
        //for arrival time..
        for(i=0;i<n;i++)
        {
            scanf("%d",&j);
            Time t;
            t.time=j;
            t.type=1;
            vt.push_back(t);
        }
        //for departure time.
        for(i=0;i<n;i++)
        {
            scanf("%d",&j);
            Time t;
            t.time=j;
            t.type=-1;
            vt.push_back(t);
        }
        //sort the time..
        sort(vt.begin(),vt.end(),compare);
        int best=0,maxx=-1;
        for(i=0;i<vt.size();i++)
        {
            best=best+vt[i].type;
            if(best>maxx)
              maxx=best;
        }
        printf("%d\n",maxx);
    }

    return 0;
}
