// find the maximum sum in array where consecutive elements would not be selected together.

#include<cstdio>
#include<algorithm>
#define N 100
using namespace std;
int a[N],dp[N],n;
int maxsum(int index)
{
   if(index>=n) return  0;
   if(index==n-1)return a[index];
   if(dp[index]!=-1) return dp[index];
   return dp[index]=max(a[index]+maxsum(index+2),maxsum(index+1));
}
int main()
{
   int i,j,k,ans;
   scanf("%d",&n);
   for(i=0;i<n;i++)
   scanf("%d",&a[i]);
   printf("\n print the elemnet");
   for(i=0;i<n;i++)
   printf("%d ",a[i]);
   for(i=0;i<n;i++)
   dp[i]=-1;
   printf("maximum sum:%d",max(a[0]+maxsum(2),maxsum(1)));
   return 0;
 }
