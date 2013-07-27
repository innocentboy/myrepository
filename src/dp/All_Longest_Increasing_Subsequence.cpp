/**
THIS FILE PRINTS THE ALL COMBINATION OF LONGEST INCREASING SUBSEQUENCES..
*/

#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>
#define N 100
using namespace std;

int a[N],dp[N];
vector< pair<int,int> > arr[N];
set<string> uniq;
vector<string> res;



void allIncreasingSubsquence(int len,string str,int maxlen,int greater)
{
  int i,j,k,d;
  d=maxlen;
  if(d==0)
  {
    if(uniq.count(str)==0)
    {
      uniq.insert(str);
      res.push_back(str);
    }
  }
  if(d<0) return ;
  k=arr[d].size();
  for(i=0;i<k;i++)
  {
    pair<int,int> pr;
    pr=arr[d][i];
    char c='0'+pr.second;
    if(pr.first<len&&pr.second<greater)
    {
        allIncreasingSubsquence(pr.first,c+str,maxlen-1,pr.second);
    }
  }
}


int main()
{

     int i,j,k,l,m,n,lenmax;
     scanf("%d",&n);
     for(i=0;i<n;i++)
     scanf("%d",&a[i]);
     /**
     CODE FOR FINDING INCREASING SUBSEQUENCE.
     */

     dp[0]=1;
     for(i=1;i<n;i++)
     {
       dp[i]=1;
       for(j=0;j<i;j++)
       {
          if(a[i]>a[j]&&dp[i]<dp[j]+1)
          dp[i]=dp[j]+1;
        }
     }

     lenmax=-1;
     for(i=0;i<n;i++)
     {
        lenmax=max(lenmax,dp[i]);
     }

     for(i=0;i<n;i++)
     {
        arr[dp[i]].push_back(make_pair(i,a[i]));
      }

     allIncreasingSubsquence(n,"",lenmax,11);
     sort(res.begin(),res.end());
     for(i=0;i<res.size();i++)
     {
       cout<<res[i]<<endl;
    }
     return 0;
}
