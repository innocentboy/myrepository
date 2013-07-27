/**



*/
#include<cstdio>
#include<iostream>
#define N 50009
long long a[N],dp[N];
int main()
{
   int i,j,k,t,n;
   long long ans=0;
   scanf("%d",&t);
   while(t--)
   {
      scanf("%d",&n);
      ans=0;
      for(i=0;i<n;i++)
      scanf("%lld",&a[i]);
      int max=-1;
      dp[n-1]=0;max=a[n-1];
      for(i=n-2;i>=0;i--)
      {
         dp[i]=max;
         if(max<a[i])
         max=a[i];
      }
     /* printf("\n");
      for(i=0;i<n;i++)
      printf("%d ",dp[i]);
      printf("\n");*/

      for(i=0;i<n;i++)
      {
        if(dp[i]-a[i]>0)
        {
          ans+=dp[i]-a[i];
        }
        dp[i]=0;
      }
       printf("%lld\n",ans);
    }
   return 0;
}
