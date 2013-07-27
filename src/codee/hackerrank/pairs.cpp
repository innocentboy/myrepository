/**


*/

#include<cstdio>
#include<algorithm>
#include<math.h>
#include<vector>
#include<set>
#define N 100006
using namespace std;
set<int> s;
int main()
{
    int i,j,n,k;
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++)
    {
      scanf("%d",&j);
      s.insert(j);
    }
    int ans=0;
    set<int>::iterator it=s.begin();
    for(;it!=s.end();it++)
    {
      i=*it;j=i-k;
     // printf("%d %d\n",i,j);
      if(j!=i&&(s.find(j)!=s.end()))
      ans++;
    }
    printf("%d\n",ans);
}
