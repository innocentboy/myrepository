/**
http://www.codechef.com/FEB14/problems/TWODOGS
*/

/**
Sample Input 1:
5 5
2 4 3 2 1

Sample Output 1:
2

Sample Input 2:
5 5
2 4 9 2 5

Sample Output 2:
-1

Sample Input 3:
8 5
2 4 3 10 1 7 5 6

Sample Output 3:
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
using namespace  std;
#define N 500005
#define M 1000000007

bool compare(const pair<int,int> &aa,const pair<int,int> &bb)
{
    return aa.first<bb.first;
}

int main()
{
    int i,j,k,n,t;
    vector< pair<int,int> > vt;
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;i++){
        scanf("%d",&j);
        pair<int,int> pr;
        pr.first=j;pr.second=i;
        vt.push_back(pr);
    }
    int maxx=M;
    //sort the array..
    sort(vt.begin(),vt.end(),compare);

    printf("\nprint the sorted array..\n");
    for(i=0;i<n;i++)
      printf("%d ",vt[i].first);

    i=0;j=vt.size()-1;
    while(i<j)
    {
      int temp=vt[i].first+vt[j].first;
      if(temp==k&& vt[i].first!=vt[j].first)
      {
        int ii,jj;
        ii=vt[i].second;jj=vt[j].second;

      //  printf("\n%d %d\n",ii,jj);

        if(ii>jj)
          ii^=jj^=ii^=jj;

       // printf("\n%d %d\n",ii,jj);

        maxx=min(maxx,min(min(jj,n-ii+1),(ii>(n-jj+1)?ii:(n-jj+1))));
        i++;j--;

        //
        //printf("\n%d %d %d %d %d\n",ii,jj,maxx,i,j);
      }
      else if(temp>k) j--;
      else i++;
    }

    if(maxx!=M)
    {
      printf("%d\n",maxx);
    }
    else
      printf("-1\n");

    return 0;
}
