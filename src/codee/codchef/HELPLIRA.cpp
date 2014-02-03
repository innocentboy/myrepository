/**
http://www.codechef.com/OCT13/problems/HELPLIRA
*/
/**
NOTE: Basically this problem is for cmputing the Area of the triangle.
*/

#include <cstdio>
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <map>
#include <cmath>
#include <cstring>
using namespace  std;
#define N 1005
#define M 1000000007

double area(int x1,int y1,int x2,int y2,int x3,int y3)
{
    double ans=0;
    ans=(x2*y3+x3*y1+x1*y2)-(x3*y2+x1*y3+x2*y1);
    if(ans<0) ans=-ans;
    return (ans)/2;
}

int main()
{
    int i,j,k,t,n;
    int x1,x2,x3,y1,y2,y3;
    double sarea=M,larea=-M,ans=0;
    scanf("%d",&n);
    i=1;
    while(n--)
    {
        scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3);
        ans=area(x1,y1,x2,y2,x3,y3);
        if(ans<=sarea)
        {
          sarea=ans;
          j=i;
        }
        if(ans>=larea)
        {
            larea=ans;
            k=i;
        }
        i++;
    }
    printf("%d %d\n",j,k);

    return 0;
}
