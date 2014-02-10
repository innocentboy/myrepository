/**

*/
/**

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
#define N 100005

map<int,int> mp;

int main()
{
    int i,j,k,n1,n2,n3;
    scanf("%d%d%d",&n1,&n2,&n3);
    for(i=0;i<n1;i++)
    {
        scanf("%d",&j);
        mp[j]++;
    }
    for(i=0;i<n2;i++)
    {
        scanf("%d",&j);
        mp[j]++;
    }
    for(i=0;i<n3;i++)
    {
        scanf("%d",&j);
        mp[j]++;
    }
    //now filter the id's..
    map<int,int>::iterator it;
    it=mp.begin();
    vector<int> id;
    for(;it!=mp.end();it++)
    {
      if(it->second>1)
            id.push_back(it->first);
    }
    printf("%d\n",id.size());
    for(i=0;i<id.size();i++)
      printf("%d\n",id[i]);

    return 0;
}
