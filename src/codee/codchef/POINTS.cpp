/**
http://www.codechef.com/problems/POINTS
*/
/**
NOTE:  WE JUST NEED TO SORT THE ELEMENT ACCORDING TO THEIR CO-ORDINATS, AND NEED TO FIND THE DISTANCE
        BETWEEN THE POINTS FROM THE SORTED POINTS.
        FOR SORTING LOOK IN TO THE COMPARE FUNCTION FOR MORE DETAILS, WHICH SORTS THE POINTS
        ACCORDING TO THE GIVEN CONSTARINTS IN THE PROBLEM.
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

typedef struct
{
   int x;
   int y;
}Point;


bool compare(const Point& a,const Point& b)
{
    if(a.x!=b.x)
      return a.x<b.x;
    else
      return a.y>b.y;
}

int main()
{
    int i,j,k,t,n;
    scanf("%d",&t);
    while(t--)
    {
        vector<Point> vt;
        scanf("");
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            Point p;
            scanf("%d%d",&j,&k);
            p.x=j;
            p.y=k;
            vt.push_back(p);
        }
        //sort the points..
        sort(vt.begin(),vt.end(),compare);

        double ans=0;
        for(i=1;i<n;i++)
        {
            ans+=sqrt(abs(vt[i].x-vt[i-1].x)*abs(vt[i].x-vt[i-1].x)+
                        abs(vt[i].y-vt[i-1].y)*abs(vt[i].y-vt[i-1].y));
        }
        printf("%.2f\n",ans);
    }

    return 0;
}
