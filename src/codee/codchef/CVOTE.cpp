/**
http://www.codechef.com/problems/CVOTE
*/
/**
Input:
1 3
Leibniz Germany
Leibniz
Leibniz
Leibniz

Output:
Germany
Leibniz
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
#define N 100
#define M 100
#define INF 1000000000

char s1[N],s2[N];

int main()
{
    int i,j,k,n,m;
    map<string,string> mp;
    map<string,int> chef;
    map<string,int>::iterator itChef;
    map<string,string>::iterator it;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
    {
        scanf("%s%s",s1,s2);
        //printf("%s %s\n",s1,s2);
        mp[s1]=s2;
    }
    int max=0;
    for(i=0;i<m;i++)
    {
        scanf("%s",s1);
        chef[s1]++;
        if(chef[s1]>max)
            max=chef[s1];
    }
    printf("\nsome ..\n");
    //Now find the chef with max vote..
    set<string> st;
    itChef=chef.begin();
    for(;itChef!=chef.end();itChef++)
    {
        printf("\n%s %d %d\n",itChef->first,itChef->second,max);
        if(itChef->second==max)
        {
            st.insert(itChef->first);
        }
    }
    //Now get the country
    printf("\noutside \n");
    set<string> country;
    set<string>::iterator itr;
    itr=st.begin();
    for(;itr!=st.end();itr++)
    {
        country.insert(mp[*itr]);
    }
    printf("\nAns:%s %s\n",*country.begin(),*st.begin());


    return 0;
}
