/**
this file includes int different demos of available stl of c++;
*/

#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<deque>
#include<bitset>
#include<algorithm>
#include<cmath>
#include<string>
#define N 1000
using namespace std;
/*inline bool compare(int a,int b)
{
  if(a>b) return true;
  else return false;
}
*/

/*class cmp:Compare
{

}*/

void set_demo()
{
   set<int> st;
   set<int>::iterator it;
//   set<int>::value_compare=compare;
   pair<set<int>::iterator,bool> ret;
   st.insert(20);
   ret=st.insert(40);
   printf("\npointer :%d",*(ret.first));
   ret=st.insert(10);printf("\npointer :%d",*(ret.first));
   ret=st.insert(15);printf("\npointer :%d",*(ret.first));
   it=st.begin();printf("\n");
   while(it!=st.end()){
   printf("%d ",*it);
   it++;
   }
}

void map_demo()
{
   map<char,int> mp;
   map<char,int>::iterator it;
   mp['a']=1;
   it=mp.begin();
   while(it!=mp.end())
   {
//      printf("%c ",(it.first));it++;
it++;
    }

}

int main()
{

  //set_demo();
  map_demo();
  return 0;
}
