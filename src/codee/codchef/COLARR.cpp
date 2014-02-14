/**
http://www.codechef.com/FEB14/problems/COLARR
*/

/**
Input:
2
4 2 1
1 1 2 2
1 1
1 1
1 1
3 1
0 1
0 1
1 0
1 0

4 2 1
1 1 2 2
1 1
1 1
6 1
7 3
0 1
0 1
1 0
1 0

Output:
5
10
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
#define N 1005
#define M 1005

int a[N];
int gain[N][N],lose[N][N];

bool compare(const pair<int,int> &aa,const pair<int,int> &bb)
{
    return (aa.first-gain[aa.second][a[aa.second]-1])>(bb.first-gain[bb.second][a[bb.second]-1]);
}

int main()
{
    int i,j,k,n,m,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&m,&k);
        for(i=0;i<n;i++)
          scanf("%d",&a[i]);
        //gain matrix..
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
             scanf("%d",&gain[i][j]);
        }
        //lose matrix..
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
             scanf("%d",&lose[i][j]);
        }
        //create the vector..
        vector< pair<int,int> > vt;
        for(i=0;i<n;i++)
        {
            int maxx=0;
            for(j=0;j<m;j++)
            {
              if((gain[i][j]-lose[i][j])>maxx)
              {
                 maxx= gain[i][j]-lose[i][j];
              }
            }
            if(maxx>(gain[i][a[i]-1]-lose[i][a[i]-1]))
            {
              vt.push_back(make_pair(maxx,i));
            }
        }

        //sort the vector..
        sort(vt.begin(),vt.end(),compare);

        int mark[N];
        for(i=0;i<n;i++)
        {
           mark[i]=1;
        }
        i=0;
        long long ans=0;
        while(k>0&&i<vt.size())
        {
          pair<int,int> p=vt[i];
          ans+=p.first;
          mark[p.second]=0;
          k--;
          i++;
        }
        //Now for the rest array..
        for(i=0;i<n;i++)
        {
          if(mark[i]==1)
          {
             ans+=gain[i][a[i]-1];
           }
        }
        printf("%lld\n",ans);
    }

    return 0;
}
