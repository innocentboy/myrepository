/**
http://www.codechef.com/problems/LELEMON
*/


/**
2
3 3
0 2 1
3 1 2 3
1 7
2 4 7
4 7
0 1 3 0 1 0 0
1 7
3 9 4 5
7 1 2 3 4 5 6 7
1 1

Output:
17
22
*/
#include<cstdio>
#include<cmath>
#include<cstring>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define N 105

bool compare(int a,int b)
{
    return a>b;
}

int main()
{
    int i,j,k,t,n,m;
    scanf("%d",&t);
    while(t--)
    {
      scanf("%d%d",&n,&m);
      vector<int> fr(n,0);
      vector< vector<int> > v(n);
      for(i=0;i<m;i++){
        scanf("%d",&j);
        fr[j]++;
      }
      long long res=0;
      for(i=0;i<n;i++)
      {
            scanf("%d",&k);
            for(j=0;j<k;j++)
            {
                int temp;
                scanf("%d",&temp);
                v[i].push_back(temp);
            }
            sort(v[i].begin(),v[i].end(),compare);
            for(j=0;j<min(fr[i],(int)v[i].size());j++)
            {
                res+=v[i][j];
            }
      }
      printf("%d\n",res);
    }

    return 0;
}
