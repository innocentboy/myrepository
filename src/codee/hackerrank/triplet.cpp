/**
There is an integer array d which does not contain more than two elements of the same value.
 How many distinct ascending triples (d[i] < d[j] < d[k], i < j < k) are present?

Input format
The first line contains an integer N denoting the number of elements
 in the array. This is followed by a single line containing N integers
 separated by a single space with no leading/trailing spaces

Sample input:
6
1 1 2 2 3 4

Sample output:
4

Explanation:
The distinct triplets are
(1,2,3)
(1,2,4)
(1,3,4)
(2,3,4

*/
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#define N 100005
using namespace std;

//int aa[100000000];
unsigned int a[N],s[N],l[N];
set< unsigned int> sm,lr;
map< unsigned int,unsigned int> mp;

int main()
{

  int i,n,j,k;
  long long  ans=0;
  scanf("%d",&n);
  for(i=0;i<n;i++)
  scanf("%d",&a[i]);
  lr.insert(a[n-1]);
  l[n-1]=0;
  set<unsigned int> ::iterator it=lr.begin();
  for(i=n-2;i>=0;i--)
  {
    it=lr.upper_bound(a[i]);
    l[i]=distance(it,lr.end());
    lr.insert(a[i]);
  }
  sm.insert(a[0]);
  s[0]=0;it=sm.begin();
  for(i=1;i<n;i++)
  {
    sm.insert(a[i]);
    it=sm.lower_bound(a[i]);
    s[i]=distance(sm.begin(),it);
    }
    for(i=0;i<n;i++)
    mp[a[i]]=-1;


    for(i=n-2;i>0;i--)
    {

      if(mp[a[i]]==-1)
      {
        mp[a[i]]=l[i];
        ans+=((long long)l[i])*s[i];
      }
      else
      {
         ans+=((long long)(l[i]-mp[a[i]]))*s[i];
       }
    }
    printf("%lld\n",ans);
  return 0;
}
