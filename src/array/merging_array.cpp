/*
this file find the median of two sorted arrays after merging them.
this file merge the sorted array into a sorted array with complexity of NLOGN.
*/

#include<cstdio>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<math.h>
#define N 10000
#define MAX 9999
using namespace std;
int a[N],b[N],c[N],n;
set <int> st;
set <int>::iterator it;

int main()
{

  //printf("random:%d",rand()%5);
  st.clear();
  int i,j,k;
  scanf("%d",&n);
  for(i=0;i<n;i++)
  scanf("%d",&a[i]);
  for(i=0;i<n;i++)
  {
     st.insert(a[i]);it=st.find(a[i]);
    // printf("%d %d ",i,*it);
     it++;
    // printf("%d \n",*it);
     if(it!=st.end())st.erase(it);it=st.begin();printf("\n");
     while(it!=st.end()){
     printf("%d ",*it);
     it++;
     }

   }
   printf("\nsize:%d",st.size());
  return 0;
}
