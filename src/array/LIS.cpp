/**
THIS FIEL FINDS THE LENGTH OF THE LONGEST INCREASING SUBSEQUENCE.
*/

#include<cstdio>
#include<iostream>
#include<set>
#include<algorithm>
#include<vector>
#define N 100
#define M 9999999
using namespace std;

int arr[N];
vector<int> dp(N);

/**
METHOD 1: O(N2)
*/



/**
METHOD 2: O(N LOG N)
*/

void LIS_2(int n)
{
   int i,j,k,m;
   for(i=1;i<N;i++)
   dp[i]=M;
   dp[0]=-M;
   for(i=0;i<n;i++)
   {
      j=upper_bound(dp.begin(),dp.end(),arr[i])-dp.begin();
      if(dp[j-1]<arr[i]&&arr[i]<dp[j])
      dp[j]=arr[i];
      printf("\nUpper Bound:%d  elementdp[j]:%d\n",j,dp[j]);
    }
    for(i=1;i<n;i++)
    {
      if(dp[i]==M)
      break;
      else printf("%d ",dp[i]);
    }
    printf("\nMaximum increasing sequence:%d\n",i-1);
}

int main()
{
    int i,j,k,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    scanf("%d",&arr[i]);
    LIS_2(n);

    return 0;
}
